/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 22:02:15 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/17 22:02:16 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "keycode.h"
# include "libft.h"
# include "mlx.h"
# include "math.h"
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# define W 1600
# define H 800
# define ZOOM 5.0
# define NAME "./fractol"

typedef struct	s_fract
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_ptr;
	int			endian;
	int			sl;
	int			bpp;
	int			fract_v;
	double		max_i;
	double		mv_x;
	double		mv_y;
	double		zoom;
	double		o_re;
	double		o_im;
	double		n_re;
	double		n_im;
	double		c_re;
	double		c_im;
	int			y;
	int			x;
	double		i;
	double		mouse_x;
	double		mouse_y;
	double		cnt_re;
	double		cnt_im;
	double		m_re;
	double		m_im;
	double		col;
	int			check;
	int			redraw;
	int			stop;
	double		pr;
	double		pi;
}				t_fract;

void			init_fract_man(t_fract *fract);
void			init_fract_jul(t_fract *fract);
void			init_fract_bur(t_fract *fract);
void			init_fract_burbuf(t_fract *fract);
void			init_cub_buf(t_fract *fract);
void			init_man_hor(t_fract *fract);
void			init_cub_mand(t_fract *fract);
void			init_man4(t_fract *fract);

void			julia(t_fract *fract);
void			mandelbrot(t_fract *fract);
void			burn_ship(t_fract *fract);
void			burning_shipbuf(t_fract *fract);
void			burbuf(t_fract *fract);
void			cub_buf(t_fract *fract);
void			mand_hor(t_fract *fract);
void			cub_mand(t_fract *fract);
void			man_4(t_fract *fract);

void			mlx_win_init(t_fract *fract);
void			help(t_fract *fract);
void			choosen(char *av, t_fract *fract);

void			draw(t_fract *fract);
void			redraw(t_fract *fract);
void			ft_img(t_fract *fract);

int				user_hook(int keycode, t_fract *fract);
int				user_hook2(int keycode, t_fract *fract);
int				mouse_hook(int	x, int y, t_fract *fract);

void			move(int k, t_fract *fract);
int				mouse_scr(int key, int x, int y, t_fract *fract);
void			mouse_zoom(int k, t_fract *fract, int x, int y);

int				rotate_fract(int k, t_fract *fract);
int				rotate_fract2(int k, t_fract *fract);

#endif
