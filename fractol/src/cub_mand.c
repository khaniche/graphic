/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:22:28 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/30 13:22:30 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_cub(t_fract *fract)
{
	double	pr;
	double	pi;
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
		fract->n_im = ((zrsqr * 3.0) - zisqr) * fract->o_im + fract->pi;
		fract->n_re = (zrsqr - (zisqr * 3.0)) * fract->o_re + fract->pr;
		if ((fract->n_re * fract->n_re + fract->n_im * fract->n_im) > 4)
		{
			ft_img(fract);
			break ;
		}
	}
}

void		cub_mand(t_fract *fract)
{
	if (fract->redraw == 1)
		init_cub_mand(fract);
	fract->y = -1;
	while (++fract->y < H)
	{
		fract->x = -1;
		while (++fract->x < W)
			draw_cub(fract);
	}
}
