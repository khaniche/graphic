/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:23:38 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/30 13:23:39 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		move(int k, t_fract *fract)
{
	if (k == 124)
		fract->mv_x -= 0.1;
	if (k == 125)
		fract->mv_y -= 0.1;
	if (k == 123)
		fract->mv_x += 0.1;
	if (k == 126)
		fract->mv_y += 0.1;
}

void		mouse_zoom(int k, t_fract *fract, int x, int y)
{
	fract->cnt_re = 0 / (0.5 * fract->zoom * W) + fract->mv_x;
	fract->cnt_im = 0 / (0.5 * fract->zoom * H) + fract->mv_y;
	fract->m_re = 1.5 * ((double)x - W / 2)
	/ (0.5 * fract->zoom * W) + fract->mv_x;
	fract->m_im = ((double)y - H / 2)
		/ (0.5 * fract->zoom * H) + fract->mv_y;
	fract->mv_x -= fract->cnt_re - fract->m_re;
	fract->mv_y -= fract->cnt_im - fract->m_im;
	if (k == 4)
		fract->zoom < 207677431915418 ? fract->zoom *= 1.05 : fract->zoom;
	if (k == 5)
		fract->zoom > 0.0005 ? fract->zoom /= 1.05 : fract->zoom;
	fract->cnt_re = 0 / (0.5 * fract->zoom * W) + fract->mv_x;
	fract->cnt_im = 0 / (0.5 * fract->zoom * H) + fract->mv_y;
	fract->m_re = 1.5 * ((double)x - W / 2)
		/ (0.5 * fract->zoom * W) + fract->mv_x;
	fract->m_im = ((double)y - H / 2)
		/ (0.5 * fract->zoom * H) + fract->mv_y;
	fract->mv_x += fract->cnt_re - fract->m_re;
	fract->mv_y += fract->cnt_im - fract->m_im;
	mlx_clear_window(fract->mlx, fract->win);
	draw(fract);
}

void		backgr_menu(t_fract *fract)
{
	unsigned	col;

	col = 0x0000FF;
	fract->y = -1;
	while (++fract->y < 145)
	{
		fract->x = -1;
		while (++fract->x < 505)
			mlx_pixel_put(fract->mlx, fract->win, fract->x, fract->y, col);
	}
}

void		help(t_fract *fract)
{
	backgr_menu(fract);
	mlx_string_put(fract->mlx, fract->win, 10, 0, 0xC0C0C0,
		"1 - \"1-8\" on rightpad to change the fractal");
	mlx_string_put(fract->mlx, fract->win, 10, 20, 0xC0C0C0,
		"2 - \"D\" to switch on default place");
	mlx_string_put(fract->mlx, fract->win, 10, 40, 0xC0C0C0,
		"3 - Click arrows up, down, right, left to move");
	mlx_string_put(fract->mlx, fract->win, 10, 60, 0xC0C0C0,
		"4 - \"Space\" to stop and \"P\" to continue");
	mlx_string_put(fract->mlx, fract->win, 10, 80, 0xC0C0C0,
		"5 - \"C\" to take psychedelics and \"D\" to stop this");
	mlx_string_put(fract->mlx, fract->win, 10, 100, 0xC0C0C0,
		"6 - \"+\" \"-\" to increase the number of iterations");
	mlx_string_put(fract->mlx, fract->win, 10, 120, 0xC0C0C0,
		"7 - \"scroll up\" and \"scroll down\" to zoom");
}
