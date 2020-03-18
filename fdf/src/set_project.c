/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:20:16 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/13 15:20:17 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_fdf *fdf)
{
	ft_putstr("PROJECTION: def\n");
	fdf->projection = 0;
}

void	set_iso(t_fdf *fdf)
{
	ft_putstr("PROJECTION: iso\n");
	fdf->projection = 1;
}

void	set_par(t_fdf *fdf)
{
	ft_putstr("PROJECTION: front\n");
	fdf->projection = 2;
}

void	set_rand(t_fdf *fdf)
{
	ft_putstr("PROJECTION: rand\n");
	fdf->projection = 3;
}

void	set_front(t_fdf *fdf)
{
	ft_putstr("PROJECTION: front\n");
	fdf->projection = 4;
}
