/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:26:04 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/29 15:26:07 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_cub_buf(t_fract *fract)
{
	fract->zoom = 1;
	fract->mv_x = -0.25;
	fract->mv_y = -0.25;
	fract->col = 1;
	fract->max_i = 100;
}

void	init_man_hor(t_fract *fract)
{
	fract->zoom = 1;
	fract->mv_x = 0;
	fract->mv_y = 0;
	fract->n_re = 0;
	fract->n_im = 0;
	fract->col = 1;
	fract->max_i = 100;
}

void	init_cub_mand(t_fract *fract)
{
	fract->zoom = 1;
	fract->mv_x = 0;
	fract->mv_y = 0;
	fract->col = 1;
	fract->max_i = 100;
}

void	init_man4(t_fract *fract)
{
	fract->zoom = 1;
	fract->mv_x = 0;
	fract->mv_y = 0;
	fract->col = 1;
	fract->max_i = 100;
}
