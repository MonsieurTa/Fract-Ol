/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:11:16 by wta               #+#    #+#             */
/*   Updated: 2018/12/03 17:43:58 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_move(int keycode, t_mlx *mlx)
{
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
	{
		if (keycode == 0)
			mlx->setpos.xoffset += 10 * ((mlx->setpos.xmax - mlx->setpos.xmin)
					/ SCREEN_W);
		if (keycode == 1)
			mlx->setpos.yoffset -= 10 * ((mlx->setpos.ymax - mlx->setpos.ymin)
					/ SCREEN_W);
		if (keycode == 2)
			mlx->setpos.xoffset -= 10 * ((mlx->setpos.xmax - mlx->setpos.xmin)
					/ SCREEN_W);
		if (keycode == 13)
			mlx->setpos.yoffset += 10 * ((mlx->setpos.ymax - mlx->setpos.ymin)
					/ SCREEN_W);
		draw_all(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
}

void	maxiter_mod(int keycode, t_mlx *mlx)
{
	if (keycode == 116 || keycode == 121)
	{
		if (keycode == 116 && mlx->maxiter < 500)
			mlx->maxiter += 2;
		if (keycode == 121 && mlx->maxiter > 500)
			mlx->maxiter -= 2;
		draw_all(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
}

void	reset(int keycode, t_mlx *mlx)
{
	if (keycode == 49)
	{
		init_spec(mlx);
		draw_all(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
}

void	change_color(int keycode, t_mlx *mlx)
{
	if (keycode == 36)
	{
		mlx->ncolor += 1;
		draw_all(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
}
