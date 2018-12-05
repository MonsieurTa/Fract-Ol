/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 11:32:04 by wta               #+#    #+#             */
/*   Updated: 2018/12/02 11:37:46 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	select_fractal(int keycode, t_mlx *mlx)
{
	if (keycode == 18 && !(mlx->fractal & MANDELBROT))
	{
		init_spec(mlx);
		mlx->fractal = MANDELBROT;
	}
	if (keycode == 19 && !(mlx->fractal & JULIA))
	{
		init_spec(mlx);
		mlx->fractal = JULIA;
	}
	if (keycode == 20 && !(mlx->fractal & TRICORN))
	{
		init_spec(mlx);
		mlx->fractal = TRICORN;
	}
	if (keycode == 21 && !(mlx->fractal & BURNING))
	{
		init_spec(mlx);
		mlx->fractal = BURNING;
	}
	if (keycode == 23 && !(mlx->fractal & LOL))
	{
		init_spec(mlx);
		mlx->fractal = LOL;
	}
}

void	change_fractal(int keycode, t_mlx *mlx)
{
	if (keycode == 18 || keycode == 19 || keycode == 20 || keycode == 21
			|| keycode == 23)
	{
		select_fractal(keycode, mlx);
		draw_all(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
}
