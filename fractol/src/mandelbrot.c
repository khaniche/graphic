/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:20:21 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/28 14:20:23 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw3(t_fract *fract)
{
	fract->i = -1;
	fract->pr = 1.5 * (fract->x - W / 2) / (0.3 * fract->zoom * W) +
	fract->mv_x;
	fract->pi = (fract->y - H / 2) / (0.3 * fract->zoom * H) + fract->mv_y;
	fract->n_re = 0;
	fract->n_im = 0;
	while (++fract->i < (int)fract->max_i)
	{
		fract->o_re = fract->n_re;
		fract->o_im = fract->n_im;
		fract->n_re = fract->o_re * fract->o_re - fract->o_im * fract->o_im +
		fract->pr;
		fract->n_im = 2 * fract->o_re * fract->o_im + fract->pi;
		if ((fract->n_re * fract->n_re + fract->n_im * fract->n_im) > 4)
		{
			ft_img(fract);
			break ;
		}
	}
}

void		mandelbrot(t_fract *fract)
{
	if (fract->redraw == 1)
		init_fract_man(fract);
	fract->y = -1;
	while (++fract->y < H)
	{
		fract->x = -1;
		while (++fract->x < W)
			draw3(fract);
	}
}
