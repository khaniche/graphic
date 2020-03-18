/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:23:53 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/30 13:23:54 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_jul(t_fract *fract)
{
	fract->i = -1;
	fract->n_re = 1.5 * (fract->x - W / 2) / (0.3 * fract->zoom * W) +
	fract->mv_x;
	fract->n_im = (fract->y - H / 2) / (0.3 * fract->zoom * H) + fract->mv_y;
	while (++fract->i < (int)fract->max_i)
	{
		fract->o_re = fract->n_re;
		fract->o_im = fract->n_im;
		fract->n_re = fract->o_re * fract->o_re - fract->o_im *
		fract->o_im + fract->c_re;
		fract->n_im = 2 * fract->o_re * fract->o_im + fract->c_im;
		if ((fract->n_re * fract->n_re + fract->n_im * fract->n_im) > 4)
		{
			ft_img(fract);
			break ;
		}
	}
}

void		julia(t_fract *fract)
{
	if (fract->redraw == 1)
		init_fract_jul(fract);
	fract->y = -1;
	while (++fract->y < H)
	{
		fract->x = -1;
		while (++fract->x < W)
			draw_jul(fract);
	}
}
