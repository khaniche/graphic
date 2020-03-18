/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:15:32 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/14 14:15:34 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include "keycode.h"
# include <errno.h>
# include <stdio.h>
# define WINWIDTH 			1920
# define WINHEIGHT 			1080
# define KEYPRESS			2
# define KEYRELEASE			3
# define KEYPRESSMASK		(1L << 0)
# define KEYRELEASEMASK		(1L << 1)
# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D
# define COLOR_DEFAULT		0xFFLLU

typedef struct		s_point
{
	double			y;
	double			x;
	double			z;
	double			s_y;
	double			s_x;
	double			s_z;
	int				yy;
	int				xx;
	double			zz;
}					t_point;

typedef struct		s_points
{
	t_point			**point;
	size_t			len;
}					t_points;

typedef struct		s_braz
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	int				incx;
	int				incy;
}					t_braz;

typedef struct		s_fdf
{
	t_point			max;
	void			*mlx;
	void			*win;
	size_t			scale;
	t_point			**point;
	size_t			projection;
	size_t			color;
	t_point			**map;
	double			max_z;
	double			max_y;
	double			max_x;
	double			min_z;
	double			min_y;
	int				deltax;
	int				deltay;
	double			min_x;
	int				movex;
	int				movey;
}					t_fdf;

typedef struct		s_split
{
	char			**str;
	size_t			len;
}					t_split;

void				draw(t_fdf *fdf);
void				read_map(int fd, t_fdf *fdf);
t_point				*get_c(size_t y, t_split *line, t_fdf *fdf);
int					user_hook(int keycode, t_fdf *fdf);
void				projection(t_fdf *info);
void				scale(t_fdf *fdf);
void				max_val(int	i, t_fdf *fdf);

void				set_iso(t_fdf *fdf);
void				set_default(t_fdf *fdf);
void				set_rand(t_fdf *fdf);
void				set_front(t_fdf *fdf);
void				set_par(t_fdf *fdf);
void				def(t_point *point);

void				s(double *x, double *y, double z);
void				par(double *x, double *y, double z);
void				front(double *x, double *y, double z);
void				iso(double *x, double *y, double z);

void				left_move(t_fdf *fdf);
void				right_move(t_fdf *fdf);
void				up_move(t_fdf *fdf);
void				down_move(t_fdf *fdf);
void				zoom(t_fdf *fdf);

void				help(t_fdf *fdf);
void				user_hook2(int keycode, t_fdf *fdf);
void				user_hook3(int keycode, t_fdf *fdf);

void				p_3d_x(t_fdf *fdf);
void				p_3d_y(t_fdf *fdf);
void				p_3d_z(t_fdf *fdf);

void				init(t_fdf *fdf);
void				check_av(char **av);
void				error(char *str);
void				min_x(t_fdf *fdf);
void				max_x(t_fdf *fdf);

#endif
