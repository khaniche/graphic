/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swticth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:46:16 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/30 13:46:17 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rotate_fract2(int k, t_fract *fract)
{
	if (k == 83)
	{
		fract->fract_v = 0;
		choosen("1", fract);
	}
	if (k == 84)
	{
		fract->fract_v = 1;
		choosen("2", fract);
	}
	if (k == 85)
	{
		fract->fract_v = 2;
		choosen("3", fract);
	}
	if (k == 86)
	{
		fract->fract_v = 3;
		choosen("4", fract);
	}
	return (0);
}

int	rotate_fract(int k, t_fract *fract)
{
	rotate_fract2(k, fract);
	if (k == 87)
	{
		fract->fract_v = 4;
		choosen("5", fract);
	}
	if (k == 88)
	{
		fract->fract_v = 5;
		choosen("6", fract);
	}
	if (k == 89)
	{
		fract->fract_v = 6;
		choosen("7", fract);
	}
	if (k == 91)
	{
		fract->fract_v = 7;
		choosen("8", fract);
	}
	return (0);
}
