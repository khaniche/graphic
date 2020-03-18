/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:34:26 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/30 13:34:27 by khaniche         ###   ########.fr       */
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

static void	draw2(t_fract *fract)
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
		fract->n_im = 4 * fract->o_im * fract->o_re * (zrsqr - zisqr)
		+ fract->pi;
		fract->n_re = zrsqr * zrsqr + zisqr * zisqr - 6 * zrsqr
		* zisqr + fract->pr;
		if (part(fract) == 0)
			break ;
	}
}

void		man_4(t_fract *fract)
{
	if (fract->redraw == 1)
		init_man4(fract);
	fract->y = -1;
	while (++fract->y < H)
	{
		fract->x = -1;
		while (++fract->x < W)
			draw2(fract);
	}
}
