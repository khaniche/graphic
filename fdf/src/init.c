/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 19:07:13 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/21 19:07:14 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_av(char **av)
{
	char	*res;

	res = ft_strstr(av[1], ".fdf");
	if (res == 0)
		error("Usage /fdf \"42\", or other maps");
}

void	init(t_fdf *fdf)
{
	fdf->max_z = 0;
	fdf->movex = 0;
	fdf->movey = 0;
	fdf->max.x = 0;
	fdf->color = 0xFFLLU;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WINWIDTH, WINHEIGHT, "khaniche");
}

void	max_val(int i, t_fdf *fdf)
{
	if (fdf->max_z < i)
		fdf->max_z = i;
}
