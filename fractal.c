/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:20:37 by wta               #+#    #+#             */
/*   Updated: 2018/12/02 11:41:51 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		draw_all(t_mlx *mlx)
{
	pthread_t	threads[MAX_THREAD];
	int			index;

	index = -1;
	while (++index < MAX_THREAD)
		if ((pthread_create(&threads[index], NULL,
			(void*)fractal, mlx) == -1))
			return (0);
	index = -1;
	while (++index < MAX_THREAD)
		if ((pthread_join(threads[index], NULL)) != 0)
			return (0);
	mlx->counter = 0;
	return (1);
}

int		count_thread(int *counter)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (*counter & i)
	{
		i <<= 1;
		count++;
	}
	*counter |= i;
	return (count);
}

int		escape_time(int x, int y, t_mlx *mlx)
{
	int		iter;
	t_tool	tool;

	iter = -1;
	if (mlx->fractal & MANDELBROT)
		set_mandelbrot(&tool, mlx, x, y);
	else if (mlx->fractal & JULIA)
		set_julia(&tool, mlx, x, y);
	else if ((mlx->fractal & TRICORN) || (mlx->fractal & BURNING)
			|| (mlx->fractal & LOL))
		set_tricorn(&tool, mlx, x, y);
	if ((mlx->fractal & MANDELBROT) || (mlx->fractal & JULIA))
		iter = classic_bailout(mlx, tool);
	else if (mlx->fractal & TRICORN)
		iter = tricorn_bailout(mlx, tool);
	else if (mlx->fractal & BURNING)
		iter = burning_bailout(mlx, tool);
	else if (mlx->fractal & LOL)
		iter = lol_bailout(mlx, tool);
	return (iter);
}

void	color_img(t_mlx *mlx, int x, int y)
{
	int	iter;

	iter = escape_time(x, y, mlx);
	if (x >= 0 && x < SCREEN_W && y >= 0 && y < SCREEN_H)
	{
		if (iter < mlx->maxiter)
			*((unsigned int*)(mlx->img_str + x * mlx->bpp / 8 + y
						* mlx->sizel)) = get_color(iter, mlx->ncolor);
		else
			*((unsigned int*)(mlx->img_str + x * mlx->bpp / 8 + y
						* mlx->sizel)) = 0;
	}
}

void	fractal(t_mlx *mlx)
{
	int	max_w;
	int	count;
	int	y;
	int	x;

	y = -1;
	count = count_thread(&(mlx->counter));
	max_w = count * mlx->size_per_thread + mlx->size_per_thread;
	while (++y < SCREEN_H)
	{
		x = count * mlx->size_per_thread - 1;
		while (++x < max_w)
			color_img(mlx, x, y);
	}
}
