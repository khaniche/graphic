/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:25:32 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/14 12:25:36 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		point_pos(t_fdf *fdf, t_braz b)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, b.x1, b.y1, fdf->color);
	e = (2 * b.dy) - b.dx;
	inc1 = 2 * (b.dy - b.dx);
	inc2 = 2 * b.dy;
	while (i < b.dx)
	{
		if (e >= 0)
		{
			b.y1 += b.incy;
			e += inc1;
		}
		else
			e += inc2;
		b.x1 += b.incx;
		mlx_pixel_put(fdf->mlx, fdf->win, b.x1, b.y1, fdf->color);
		i++;
	}
}

static	void	position(t_fdf *fdf, t_braz b)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(fdf->mlx, fdf->win, b.x1, b.y1, fdf->color);
	e = (2 * b.dx) - b.dy;
	inc1 = 2 * (b.dx - b.dy);
	inc2 = 2 * b.dx;
	while (i < b.dy)
	{
		if (e >= 0)
		{
			b.x1 += b.incx;
			e += inc1;
		}
		else
			e += inc2;
		b.y1 += b.incy;
		mlx_pixel_put(fdf->mlx, fdf->win, b.x1, b.y1, fdf->color);
		i++;
	}
}

static	void	draw_line(t_fdf *fdf, t_braz b)
{
	b.dx = b.x2 - b.x1;
	b.dy = b.y2 - b.y1;
	b.dx = abs(b.dx);
	b.dy = abs(b.dy);
	b.incx = (b.x2 > b.x1) ? 1 : -1;
	b.incy = (b.y2 > b.y1) ? 1 : -1;
	if (b.dx > b.dy)
		point_pos(fdf, b);
	else
		position(fdf, b);
}

static	void	draw_y(t_fdf *fdf)
{
	t_braz	braz;
	int		j;
	int		i;

	i = -1;
	while (++i < fdf->max.y - 2)
	{
		j = -1;
		while (++j < fdf->max.x - 1)
		{
			braz.x1 = fdf->point[i][j].x + fdf->deltax;
			braz.y1 = fdf->point[i][j].y + fdf->deltay;
			braz.x2 = fdf->point[i + 1][j].x + fdf->deltax;
			braz.y2 = fdf->point[i + 1][j].y + fdf->deltay;
			draw_line(fdf, braz);
		}
	}
}

void			draw(t_fdf *fdf)
{
	t_braz	braz;
	int		j;
	int		i;

	max_x(fdf);
	i = -1;
	while (++i < fdf->max.y - 1)
	{
		j = -1;
		while (++j < fdf->max.x - 2)
		{
			braz.x1 = fdf->point[i][j].x + fdf->deltax;
			braz.y1 = fdf->point[i][j].y + fdf->deltay;
			braz.x2 = fdf->point[i][j + 1].x + fdf->deltax;
			braz.y2 = fdf->point[i][j + 1].y + fdf->deltay;
			draw_line(fdf, braz);
		}
	}
	draw_y(fdf);
}
