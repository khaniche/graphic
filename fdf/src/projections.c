/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:09:06 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/14 14:09:09 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	min_x(t_fdf *fdf)
{
	int	i;
	int	j;

	fdf->min_y = fdf->point[0][0].y;
	fdf->min_x = fdf->point[0][0].x;
	i = -1;
	while (++i < fdf->max.y - 1)
	{
		j = -1;
		while (++j < fdf->max.x - 1)
		{
			if (fdf->point[i][j].x < fdf->min_x)
				fdf->min_x = fdf->point[i][j].x;
			if (fdf->point[i][j].y < fdf->min_y)
				fdf->min_y = fdf->point[i][j].y;
		}
	}
	fdf->deltax = fdf->movex + (WINWIDTH - (fdf->max_x + fdf->min_x)) / 2;
	fdf->deltay = fdf->movey + (WINHEIGHT - (fdf->max_y + fdf->min_y)) / 2;
}

void	max_x(t_fdf *fdf)
{
	int	i;
	int	j;

	fdf->max_x = 0;
	fdf->max_y = 0;
	i = -1;
	while (++i < fdf->max.y - 1)
	{
		j = -1;
		while (++j < fdf->max.x - 1)
		{
			if (fdf->point[i][j].x > fdf->max_x)
				fdf->max_x = fdf->point[i][j].x;
			if (fdf->point[i][j].y > fdf->max_y)
				fdf->max_y = fdf->point[i][j].y;
		}
	}
	min_x(fdf);
}

void	projection(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->max.y - 1)
	{
		j = -1;
		while (++j < fdf->max.x - 1)
		{
			def(&fdf->point[i][j]);
			if (fdf->projection == 1)
				iso(&fdf->point[i][j].x, &fdf->point[i][j].y,
					fdf->point[i][j].z);
			if (fdf->projection == 2)
				par(&fdf->point[i][j].x, &fdf->point[i][j].y,
					fdf->point[i][j].z);
			if (fdf->projection == 3)
				s(&fdf->point[i][j].x, &fdf->point[i][j].y,
					fdf->point[i][j].z);
			if (fdf->projection == 4)
				front(&fdf->point[i][j].x, &fdf->point[i][j].y,
					fdf->point[i][j].z);
		}
	}
	scale(fdf);
}

void	help(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 0, 0, 4849866,
		"0-5 on rightpad to change the color of projection");
	mlx_string_put(fdf->mlx, fdf->win, 0, 20, 4849866,
		"1-5 to change the projection");
	mlx_string_put(fdf->mlx, fdf->win, 0, 40, 4849866,
		"Click up, down, right, left to move the projection");
	mlx_string_put(fdf->mlx, fdf->win, 0, 60, 4849866,
		"z, y, x, to move the projection on Z,Y,X");
}

void	scale(t_fdf *fdf)
{
	size_t	tmp;
	int		i;
	int		j;

	if (fdf->max.x < fdf->max.y)
		tmp = fdf->max.y;
	if (fdf->max.y < fdf->max.x)
		tmp = fdf->max.x;
	if (fdf->max_z > tmp)
		tmp = fdf->max_z;
	if (WINWIDTH < WINHEIGHT)
		fdf->scale = (WINWIDTH / 1.5) / tmp;
	else
		fdf->scale = (WINHEIGHT / 1.5) / tmp;
	i = -1;
	while (++i < fdf->max.y)
	{
		j = -1;
		while (++j < fdf->max.x)
		{
			fdf->point[i][j].x *= fdf->scale;
			fdf->point[i][j].y *= fdf->scale;
		}
	}
}
