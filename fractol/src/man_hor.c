/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_hor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:22:06 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/28 14:22:07 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	part(t_fract *fract)
{
	if ((fract->n_re * fract->n_re + fract->n_im * fract->n_im) > 4)
	{
		ft_img(fract);
		return (0);
	}
	return (1);
}

static void	hor(t_fract *fract)
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
		fract->n_im = fract->n_im * (5 * zrsqr * zrsqr -
			10 * zrsqr * zisqr + zisqr * zisqr) + fract->pr;
		fract->n_re = -fract->n_re * (zrsqr * zrsqr -
			10 * zrsqr * zisqr + 5 * zisqr * zisqr) + fract->pi;
		if (part(fract) == 0)
			break ;
	}
}

void		mand_hor(t_fract *fract)
{
	if (fract->redraw == 1)
		init_man_hor(fract);
	fract->y = -1;
	while (++fract->y < H)
	{
		fract->x = -1;
		while (++fract->x < W)
			hor(fract);
	}
}
