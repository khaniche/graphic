/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:50:43 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/14 13:50:44 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	p_3d_x(t_fdf *fdf)
{
	int		i;
	int		j;
	double	tmp;

	ft_putstr("Y-Axis Rotation\n");
	i = -1;
	while (++i < fdf->max.y)
	{
		j = -1;
		while (++j < fdf->max.x)
		{
			tmp = fdf->point[i][j].y;
			fdf->point[i][j].y = tmp * cos(0.2) +
				fdf->point[i][j].z * sin(0.2);
			fdf->point[i][j].z = -tmp * sin(0.2) +
				fdf->point[i][j].z * cos(0.2);
		}
	}
}

void	p_3d_y(t_fdf *fdf)
{
	int		i;
	int		j;
	double	tmp;

	ft_putstr("X-Axis Rotation\n");
	i = -1;
	while (++i < fdf->max.y)
	{
		j = -1;
		while (++j < fdf->max.x)
		{
			tmp = fdf->point[i][j].x;
			fdf->point[i][j].x = tmp * cos(0.2) +
				fdf->point[i][j].z * sin(0.2);
			fdf->point[i][j].z = -tmp * sin(0.2) +
				fdf->point[i][j].z * cos(0.2);
		}
	}
}

void	p_3d_z(t_fdf *fdf)
{
	int		i;
	int		j;
	double	tmp;
	double	tmp2;

	ft_putstr("Z-Axis Rotation\n");
	i = -1;
	while (++i < fdf->max.y)
	{
		j = -1;
		while (++j < fdf->max.x)
		{
			tmp = fdf->point[i][j].x;
			tmp2 = fdf->point[i][j].y;
			fdf->point[i][j].x = tmp * cos(0.2) -
				tmp2 * sin(0.2);
			fdf->point[i][j].y = tmp * sin(0.2) +
				tmp2 * cos(0.2);
		}
	}
}
