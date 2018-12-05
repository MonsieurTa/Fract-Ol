/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bailout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 02:13:36 by wta               #+#    #+#             */
/*   Updated: 2018/12/04 05:48:58 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		classic_bailout(t_mlx *mlx, t_tool tool)
{
	double	zrsqr;
	double	zisqr;
	int		iter;

	iter = -1;
	zrsqr = tool.z.re * tool.z.re;
	zisqr = tool.z.im * tool.z.im;
	while (++iter < mlx->maxiter && zrsqr + zisqr < 4)
	{
		tool.z.im = (tool.z.re + tool.z.im)
			* (tool.z.re + tool.z.im) - zrsqr - zisqr;
		tool.z.im += tool.c.im;
		tool.z.re = zrsqr - zisqr + tool.c.re;
		zrsqr = tool.z.re * tool.z.re;
		zisqr = tool.z.im * tool.z.im;
	}
	return (iter);
}

int		tricorn_bailout(t_mlx *mlx, t_tool tool)
{
	double	x;
	double	y;
	double	xtmp;
	int		iter;

	iter = -1;
	x = tool.z.re;
	y = tool.z.im;
	while (++iter < mlx->maxiter)
	{
		if (tool.z.re * tool.z.re + tool.z.im * tool.z.im >= 4)
			return (iter);
		xtmp = tool.z.re * tool.z.re - tool.z.im * tool.z.im + x;
		tool.z.im = -2 * tool.z.re * tool.z.im + y;
		tool.z.re = xtmp;
	}
	return (iter);
}

int		burning_bailout(t_mlx *mlx, t_tool tool)
{
	double	x;
	double	y;
	double	xtmp;
	int		iter;

	iter = -1;
	x = tool.z.re;
	y = tool.z.im;
	while (++iter < mlx->maxiter)
	{
		if (tool.z.re * tool.z.re + tool.z.im * tool.z.im >= 4)
			return (iter);
		xtmp = tool.z.re * tool.z.re - tool.z.im * tool.z.im + x;
		tool.z.im = fabs(2 * tool.z.re * tool.z.im) + y;
		tool.z.re = fabs(xtmp);
	}
	return (iter);
}

int		lol_bailout(t_mlx *mlx, t_tool tool)
{
	t_cplx	a;
	t_cplx	b;
	t_cplx	util;
	int		iter;

	iter = -1;
	a.re = tool.z.re;
	a.im = tool.z.im;
	util.re = tool.z.re * tool.z.re + tool.z.im * tool.z.im;
	util.im = a.re * a.re + a.im * a.im;
	while (++iter < mlx->maxiter
			&& util.im < 4)
	{
		b.re = (tool.z.re * a.re + tool.z.im * a.im) / util.re;
		b.im = (tool.z.re * a.im - tool.z.im * a.re) / util.re;
		a.re = sin(b.re) * cosh(b.im);
		a.im = cos(b.re) * sinh(b.im);
		util.im = a.re * a.re + a.im * a.im;
	}
	return (iter);
}
