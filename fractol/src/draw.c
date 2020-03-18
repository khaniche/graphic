/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:08:01 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/19 18:08:02 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_img(t_fract *fract)
{
	double t;

	if (fract->check == 0)
	{
		t = fract->i / fract->max_i;
		fract->img_ptr[fract->y * fract->sl + fract->x * fract->bpp / 8] =
			(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		fract->img_ptr[fract->y * fract->sl + fract->x * fract->bpp / 8 + 1] =
			(int)(15 * (1 - t) * (1 - t) * t * t * 255);
		fract->img_ptr[fract->y * fract->sl + fract->x * fract->bpp / 8 + 2] =
			(int)(9 * (1 - t) * t * t * t * 255);
	}
	else
	{
		t = fract->i / fract->max_i;
		fract->img_ptr[fract->y * fract->sl + fract->x * fract->bpp / 8] =
			(int)(8.5 * (1 - t) * (1 - t) * (1 - t) * fract->col * t * 255);
		fract->img_ptr[fract->y * fract->sl + fract->x * fract->bpp / 8 + 1] =
			(int)(15 * (1 - t) * (1 - t) * fract->col * t * t * 255);
		fract->img_ptr[fract->y * fract->sl + fract->x * fract->bpp / 8 + 2] =
			(int)(9 * (1 - t) * fract->col * t * fract->col * t * t * 255);
	}
}

void	draw(t_fract *fract)
{
	fract->img = mlx_new_image(fract->mlx, W, H);
	fract->img_ptr = mlx_get_data_addr(fract->img,
		&fract->bpp, &fract->sl, &fract->endian);
	if (fract->fract_v == 0)
		julia(fract);
	if (fract->fract_v == 1)
		mandelbrot(fract);
	if (fract->fract_v == 2)
		burn_ship(fract);
	if (fract->fract_v == 3)
		burbuf(fract);
	if (fract->fract_v == 4)
		cub_buf(fract);
	if (fract->fract_v == 5)
		mand_hor(fract);
	if (fract->fract_v == 6)
		cub_mand(fract);
	if (fract->fract_v == 7)
		man_4(fract);
	mlx_clear_window(fract->mlx, fract->win);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}

void	redraw(t_fract *fract)
{
	fract->img = mlx_new_image(fract->mlx, W, H);
	fract->img_ptr = mlx_get_data_addr(fract->img,
		&fract->bpp, &fract->sl, &fract->endian);
	if (fract->redraw == 1)
	{
		if (fract->fract_v == 0)
			julia(fract);
		if (fract->fract_v == 1)
			mandelbrot(fract);
		if (fract->fract_v == 2)
			burn_ship(fract);
		if (fract->fract_v == 3)
			burbuf(fract);
		if (fract->fract_v == 4)
			cub_buf(fract);
		if (fract->fract_v == 5)
			mand_hor(fract);
		if (fract->fract_v == 6)
			cub_mand(fract);
		if (fract->fract_v == 7)
			man_4(fract);
	}
	mlx_clear_window(fract->mlx, fract->win);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
}
