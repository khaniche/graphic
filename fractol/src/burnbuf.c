/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnbuf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:26:52 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/30 13:26:53 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_fract(t_fract *fract)
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
		fract->n_im = fabs(fract->o_im * (5 * (zrsqr * zrsqr) - 10 *
			(zisqr * zrsqr) + (zisqr * zisqr))) + fract->pi;
		fract->n_re = fabs(fract->o_re) * ((zrsqr * zrsqr) - 10 *
			(zisqr * zrsqr) + 5 * (zisqr * zisqr)) + fract->pr;
		if ((fract->n_re * fract->n_re + fract->n_im * fract->n_im) > 4)
		{
			ft_img(fract);
			break ;
		}
	}
}

void		burbuf(t_fract *fract)
{
	if (fract->redraw == 1)
		init_fract_burbuf(fract);
	fract->y = -1;
	while (++fract->y < H)
	{
		fract->x = -1;
		while (++fract->x < W)
			draw_fract(fract);
	}
}
