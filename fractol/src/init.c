/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:24:52 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/19 18:24:53 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fract_jul(t_fract *fract)
{
	fract->c_im = 0.27015;
	fract->c_re = -0.7;
	fract->zoom = 1;
	fract->mv_x = 0;
	fract->mv_y = 0;
	fract->col = 1;
	fract->max_i = 100;
}

void	init_fract_man(t_fract *fract)
{
	fract->zoom = 1;
	fract->mv_x = 0;
	fract->mv_y = 0;
	fract->col = 1;
	fract->max_i = 100;
}

void	init_fract_bur(t_fract *fract)
{
	fract->mv_x = -0.35;
	fract->mv_y = -0.5;
	fract->col = 1;
	fract->zoom = 1;
	fract->max_i = 200;
}

void	init_fract_burbuf(t_fract *fract)
{
	fract->c_im = 0.27015;
	fract->c_re = -0.7;
	fract->zoom = 1;
	fract->mv_x = 0;
	fract->mv_y = 0;
	fract->col = 1;
	fract->max_i = 200;
}
