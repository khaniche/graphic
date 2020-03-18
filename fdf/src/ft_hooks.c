/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:10:29 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/14 14:10:31 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	user_hook2(int keycode, t_fdf *fdf)
{
	if (keycode == 125)
		fdf->movey += 4;
	if (keycode == 126)
		fdf->movey -= 4;
	if (keycode == 123)
		fdf->movex -= 4;
	if (keycode == 124)
		fdf->movex += 4;
	if (keycode == 83)
		fdf->color = COLOR_DISCO;
	if (keycode == 84)
		fdf->color = COLOR_BRICK_RED;
	if (keycode == 85)
		fdf->color = COLOR_FLAMINGO;
	if (keycode == 86)
		fdf->color = COLOR_JAFFA;
	if (keycode == 87)
		fdf->color = COLOR_SAFFRON;
	if (keycode == 82)
		fdf->color = COLOR_DEFAULT;
}

void	user_hook3(int keycode, t_fdf *fdf)
{
	if (keycode == 18)
	{
		set_default(fdf);
		projection(fdf);
	}
	if (keycode == 19)
	{
		set_iso(fdf);
		projection(fdf);
	}
	if (keycode == 21)
	{
		set_front(fdf);
		projection(fdf);
	}
	if (keycode == 20)
	{
		set_rand(fdf);
		projection(fdf);
	}
	if (keycode == 23)
	{
		set_par(fdf);
		projection(fdf);
	}
}

int		user_hook(int keycode, t_fdf *fdf)
{
	user_hook2(keycode, fdf);
	user_hook3(keycode, fdf);
	if (keycode == 53)
		exit(0);
	if (keycode == 7)
		p_3d_x(fdf);
	if (keycode == 16)
		p_3d_y(fdf);
	if (keycode == 6)
		p_3d_z(fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
	if (keycode == 31)
		help(fdf);
	return (0);
}
