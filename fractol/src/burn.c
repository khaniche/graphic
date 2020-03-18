/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:11:42 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/28 14:11:43 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_b(t_fract *fract)
{
	double	tmp;
	double	pr;
	double	pi;

	tmp = 0;
	pr = 1.5 * (fract->x - W / 2) / (0.35 * fract->zoom * W) +
	fract->mv_x;
	pi = (fract->y - H / 2) / (0.35 * fract->zoom * H) + fract->mv_y;
	fract->i = -1;
	fract->n_re = 0;
	fract->n_im = 0;
	while (++fract->i < (int)fract->max_i)
	{
		fract->o_re = fract->n_re;
		fract->o_im = fract->n_im;
		tmp = fract->o_re * fract->o_re - fract->o_im * fract->o_im + pr;
		fract->n_im = fabs(2 * fract->o_re * fract->o_im) + pi;
		fract->n_re = fabs(tmp);
		if ((fract->n_re * fract->n_re + fract->n_im * fract->n_im) > 4)
		{
			ft_img(fract);
			break ;
		}
	}
}

void		burn_ship(t_fract *fract)
{
	if (fract->redraw == 1)
		init_fract_bur(fract);
	fract->x = -1;
	while (++fract->x < W)
	{
		fract->y = -1;
		while (++fract->y < H)
			draw_b(fract);
	}
}
