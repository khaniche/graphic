/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:15:32 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/28 14:15:33 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	user_hook2(int keycode, t_fract *fract)
{
	if ((keycode == 123) || (keycode == 124) ||
		(keycode == 125) || (keycode == 126))
		move(keycode, fract);
	if (keycode == 8)
	{
		fract->col++;
		fract->check = 1;
	}
	if (keycode == 2)
		fract->check = 0;
	if (keycode == 69 && fract->max_i <= 500)
		fract->max_i++;
	if (keycode == 78 && fract->max_i >= 0)
		fract->max_i--;
	if (keycode == 18)
	{
		fract->redraw = 1;
		redraw(fract);
	}
	return (0);
}

int	user_hook(int keycode, t_fract *fract)
{
	fract->redraw = 0;
	fract->stop = 0;
	user_hook2(keycode, fract);
	rotate_fract(keycode, fract);
	if (keycode == 53)
	{
		mlx_destroy_window(fract->mlx, fract->win);
		exit(0);
	}
	if (keycode == 49)
		fract->stop = 1;
	if (keycode == 40)
		fract->stop = 0;
	draw(fract);
	if (keycode == 31)
		help(fract);
	return (0);
}

int	mouse_hook(int x, int y, t_fract *fract)
{
	if (fract->stop == 0)
	{
		if (x < W && y < H && x > 0 && y > 0 && fract->fract_v == 0)
		{
			fract->c_im = (y * -1) * (2.4 / H) + 1.2;
			fract->c_re = x * (3.5 / W) - 2.5;
			fract->col++;
		}
	}
	draw(fract);
	return (0);
}

int	mouse_scr(int key, int x, int y, t_fract *fract)
{
	if ((key == 4) || (key == 5) ||
		(key == 1) || (key == 2))
		mouse_zoom(key, fract, x, y);
	draw(fract);
	return (0);
}
