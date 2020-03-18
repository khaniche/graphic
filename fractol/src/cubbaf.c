/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubbaf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:23:30 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/30 13:23:31 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_cubb(t_fract *fract)
{
	double	zrsqr;
	double	zisqr;

	fract->pr = 1.5 * (fract->x - W / 2) / (0.3 * fract->zoom * W) +
	fract->mv_x;
	fract->pi = (fract->y - H / 2) / (0.3 * fract->zoom * H) + fract->mv_y;
	fract->i = -1;
	fract->n_re = 0;
	fract->n_im = 0;
	while (++fract->i < (int)fract->max_i)
	{
		zisqr = fract->n_im * fract->n_im;
		zrsqr = fract->n_re * fract->n_re;
		fract->o_re = fract->n_re;
		fract->o_im = fract->n_im;
		fract->n_im = fabs(((zrsqr * 3) - zisqr) * fract->n_im) + fract->pr;
		fract->n_re = fabs((zrsqr - (zisqr * 3)) * fract->n_re) + fract->pi;
		if ((fract->n_re * fract->n_re + fract->n_im * fract->n_im) > 4)
		{
			ft_img(fract);
			break ;
		}
	}
}

void		cub_buf(t_fract *fract)
{
	if (fract->redraw == 1)
		init_cub_buf(fract);
	fract->y = -1;
	while (++fract->y < H)
	{
		fract->x = -1;
		while (++fract->x < W)
			draw_cubb(fract);
	}
}
