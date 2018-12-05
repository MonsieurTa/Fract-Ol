/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 02:12:52 by wta               #+#    #+#             */
/*   Updated: 2018/12/03 15:56:38 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_julia(t_tool *tool, t_mlx *mlx, int x, int y)
{
	tool->c.re = mlx->mouse.x_julia;
	tool->c.im = mlx->mouse.y_julia;
	tool->z.re = mlx->setpos.xmin + ((mlx->setpos.xmax - mlx->setpos.xmin)
		* x / SCREEN_W) + mlx->setpos.xoffset;
	tool->z.im = mlx->setpos.ymin + ((mlx->setpos.ymax - mlx->setpos.ymin)
		* y / SCREEN_W) + mlx->setpos.yoffset;
}

void	set_mandelbrot(t_tool *tool, t_mlx *mlx, int x, int y)
{
	tool->c.re = mlx->setpos.xmin + ((mlx->setpos.xmax - mlx->setpos.xmin)
		* x / SCREEN_W) + mlx->setpos.xoffset;
	tool->c.im = mlx->setpos.ymin + ((mlx->setpos.ymax - mlx->setpos.ymin)
		* y / SCREEN_W) + mlx->setpos.yoffset;
	tool->z.re = 0.0;
	tool->z.im = 0.0;
}

void	set_tricorn(t_tool *tool, t_mlx *mlx, int x, int y)
{
	tool->c.re = 0.0;
	tool->c.im = 0.0;
	tool->z.re = mlx->setpos.xmin + ((mlx->setpos.xmax - mlx->setpos.xmin)
		* x / SCREEN_W) + mlx->setpos.xoffset;
	tool->z.im = mlx->setpos.ymin + ((mlx->setpos.ymax - mlx->setpos.ymin)
		* y / SCREEN_W) + mlx->setpos.yoffset;
}
