/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 03:05:55 by wta               #+#    #+#             */
/*   Updated: 2018/12/03 15:46:52 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_scale(t_mlx *mlx)
{
	double	scalechange;
	double	factor;

	scalechange = 1.0 / mlx->zoom - mlx->setpos.scale;
	factor = 1.0 / mlx->zoom;
	mlx->setpos.scale /= mlx->zoom;
	mlx->setpos.xmin = mlx->mouse.x_set
		- fabs(mlx->mouse.x_set - mlx->setpos.xmin) * mlx->zoom;
	mlx->setpos.xmax = mlx->mouse.x_set
		+ fabs(mlx->mouse.x_set - mlx->setpos.xmax) * mlx->zoom;
	mlx->setpos.ymin = mlx->mouse.y_set
		- fabs(mlx->mouse.y_set - mlx->setpos.ymin) * mlx->zoom;
	mlx->setpos.ymax = mlx->mouse.y_set
		+ fabs(mlx->mouse.y_set - mlx->setpos.ymax) * mlx->zoom;
}

int		get_color(int i, int n)
{
	int	gradient[16];
	int	index;

	gradient[0] = 0x421e0f;
	gradient[1] = 0x19071a;
	gradient[2] = 0x09012f;
	gradient[3] = 0x040449;
	gradient[4] = 0x000764;
	gradient[5] = 0x022c8a;
	gradient[6] = 0x1852b1;
	gradient[7] = 0x397dd1;
	gradient[8] = 0x86b5e5;
	gradient[9] = 0xd3ecf8;
	gradient[10] = 0xf1e9bf;
	gradient[11] = 0xf8c95f;
	gradient[12] = 0xffaa00;
	gradient[13] = 0xcc8000;
	gradient[14] = 0x995700;
	gradient[15] = 0x6a3403;
	index = -1;
	while (++index < 16)
		gradient[index] *= n;
	return (gradient[i % 16]);
}

void	print_usage(void)
{
	ft_printf("usage : ./fractol ");
	ft_printf("[Mandelbrot | Julia | Tricorn | Burning | LOL]\n");
}
