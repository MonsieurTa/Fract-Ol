/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 02:24:19 by wta               #+#    #+#             */
/*   Updated: 2018/12/04 05:48:51 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_key(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (keycode == 53)
		exit(0);
	reset(keycode, mlx);
	change_fractal(keycode, mlx);
	change_color(keycode, mlx);
	key_move(keycode, mlx);
	maxiter_mod(keycode, mlx);
	return (0);
}

int		close_win(void)
{
	exit(0);
	return (0);
}

void	set_config(t_mlx *mlx, int x, int y)
{
	mlx->mouse.x_set = mlx->setpos.xmin + ((mlx->setpos.xmax - mlx->setpos.xmin)
		* ((double)x / SCREEN_W));
	mlx->mouse.y_set = mlx->setpos.ymin + ((mlx->setpos.ymax - mlx->setpos.ymin)
		* ((double)y / SCREEN_W));
}

int		hook_mouse(int button, int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	if (button == 1)
		mlx->mouse.lock = (mlx->mouse.lock + 1) % 2;
	if (button == 4 || button == 5)
	{
		if (button == 4 && mlx->setpos.scale > 1.0)
			mlx->zoom = 1.15;
		else if (button == 5)
			mlx->zoom = 1.0 / 1.15;
		else
			mlx->zoom = 1.0;
		mlx->mouse.x = (double)x;
		mlx->mouse.y = (double)y;
		set_config(mlx, x, y);
		set_scale(mlx);
		draw_all(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	if (!mlx->mouse.lock && mlx->fractal & JULIA)
	{
		mlx->mouse.x_julia = (mlx->setpos.xmax - mlx->setpos.xmin)
			* (((double)x - mlx->half_w) / SCREEN_W);
		mlx->mouse.y_julia = (mlx->setpos.ymax - mlx->setpos.ymin)
			* (((double)y - mlx->half_h) / SCREEN_W);
		draw_all(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	return (1);
}
