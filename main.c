/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:09:46 by wta               #+#    #+#             */
/*   Updated: 2019/02/10 22:03:08 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_mlx(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		return (0);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, SCREEN_W, SCREEN_H, "FRACT'OL");
	if (!(mlx->win_ptr))
		return (0);
	if (!(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, SCREEN_W, SCREEN_H)))
		return (0);
	if (!(mlx->img_str = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp
					, &mlx->sizel, &mlx->endian)))
		return (0);
	init_spec(mlx);
	return (1);
}

void	init_spec(t_mlx *mlx)
{
	mlx->half_w = SCREEN_W / 2.0;
	mlx->half_h = SCREEN_H / 2.0;
	mlx->zoom = 1;
	mlx->counter = 0;
	mlx->size_per_thread = SCREEN_W / MAX_THREAD;
	mlx->maxiter = 50;
	mlx->z.re = 0;
	mlx->z.im = 0;
	mlx->c.re = 0;
	mlx->c.im = 0;
	init_set(mlx);
	mlx->mouse.lock = 0;
	mlx->ncolor = 1;
}

void	init_set(t_mlx *mlx)
{
	mlx->setpos.scale = 1.0;
	mlx->setpos.xmin = -2.0;
	mlx->setpos.xmax = 2.0;
	mlx->setpos.ymin = -2.0;
	mlx->setpos.ymax = 2.0;
	mlx->setpos.xoffset = 0.0;
	mlx->setpos.yoffset = 0.0;
}

int		param_fractal(t_mlx *mlx, char *name)
{
	if (ft_strcmp(name, "Mandelbrot") == 0)
		mlx->fractal = MANDELBROT;
	else if (ft_strcmp(name, "Julia") == 0)
		mlx->fractal = JULIA;
	else if (ft_strcmp(name, "Tricorn") == 0)
		mlx->fractal = TRICORN;
	else if (ft_strcmp(name, "Burning") == 0)
		mlx->fractal = BURNING;
	else if (ft_strcmp(name, "Lol"))
		mlx->fractal = LOL;
	else
	{
		ft_printf("%s is not a valid fractal.\n", name);
		print_usage();
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
	{
		print_usage();
		return (0);
	}
	if (!param_fractal(&mlx, av[1]))
		return (0);
	if (!(init_mlx(&mlx)))
		return (0);
	draw_all(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, 4, 0, hook_mouse, &mlx);
	mlx_hook(mlx.win_ptr, 2, 0, hook_key, &mlx);
	mlx_hook(mlx.win_ptr, 6, 0, mouse_move, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, close_win, NULL);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
