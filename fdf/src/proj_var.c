/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:17:30 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/13 15:17:32 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(double *x, double *y, double z)
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	front(double *x, double *y, double z)
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0);
	*y = -z + (previous_x + previous_y) * sin(0);
}

void	par(double *x, double *y, double z)
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * -cos(0.3612312);
	*y = (previous_x + previous_y) * sin(0.3612312) - z;
}

void	s(double *x, double *y, double z)
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x + previous_y) * -cos(0.3612312);
	*y = (previous_x - previous_y) * sin(0.3612312) - z;
}

void	def(t_point *point)
{
	point->y = point->s_y;
	point->x = point->s_x;
	point->z = point->s_z;
}
