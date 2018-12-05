/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:03:29 by wta               #+#    #+#             */
/*   Updated: 2018/12/03 17:42:37 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <pthread.h>
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

# define SCREEN_W	512
# define SCREEN_H	512
# define MAX_THREAD 4
# define MANDELBROT 0x1
# define JULIA		0x2
# define TRICORN	0x4
# define BURNING	0x8
# define LOL		0x10

typedef struct	s_cplx
{
	double	re;
	double	im;
}				t_cplx;

typedef struct	s_setpos
{
	double	scale;
	double	xmin;
	double	ymin;
	double	xmax;
	double	ymax;
	double	xoffset;
	double	yoffset;
}				t_setpos;

typedef struct	s_mouse
{
	int		lock;
	double	x;
	double	y;
	double	x_set;
	double	y_set;
	double	x_julia;
	double	y_julia;
}				t_mouse;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_str;
	int			bpp;
	int			sizel;
	int			endian;
	double		half_w;
	double		half_h;
	double		zoom;
	int			counter;
	int			size_per_thread;
	int			maxiter;
	t_cplx		z;
	t_cplx		c;
	t_setpos	setpos;
	t_mouse		mouse;
	int			ncolor;
	int			fractal;
}				t_mlx;

typedef struct	s_tool
{
	t_cplx	z;
	t_cplx	c;
}				t_tool;

int				init_mlx(t_mlx *mlx);
void			init_set(t_mlx *mlx);
void			init_mouse(t_mlx *mlx);
void			init_spec(t_mlx *mlx);
void			set_scale(t_mlx *mlx);
int				draw_all(t_mlx *mlx);
int				count_thread(int *counter);
int				escape_time(int x, int y, t_mlx *mlx);
void			color_img(t_mlx *mlx, int x, int y);
void			fractal(t_mlx *mlx);
int				classic_bailout(t_mlx *mlx, t_tool tool);
int				tricorn_bailout(t_mlx *mlx, t_tool tool);
int				burning_bailout(t_mlx *mlx, t_tool tool);
int				lol_bailout(t_mlx *mlx, t_tool tool);
int				get_color(int i, int n);
void			set_julia(t_tool *tool, t_mlx *mlx, int x, int y);
void			set_mandelbrot(t_tool *tool, t_mlx *mlx, int x, int y);
void			set_tricorn(t_tool *tool, t_mlx *mlx, int x, int y);

double			interpolate(double x1, double x2, double factor);
void			scale_set(t_mlx *mlx);

void			change_fractol(int keycode, t_mlx *mlx);
int				hook_mouse(int button, int x, int y, void *param);
int				close_win(void);
int				hook_key(int keycode, void *param);
int				mouse_move(int x, int y, void *param);
void			reset(int keycode, t_mlx *mlx);
void			change_fractal(int keycode, t_mlx *mlx);
void			change_color(int keycode, t_mlx *mlx);
void			key_move(int keycode, t_mlx *mlx);
void			maxiter_mod(int keycode, t_mlx *mlx);

void			print_usage(void);

#endif
