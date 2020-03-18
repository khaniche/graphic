/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:43:26 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/17 18:43:28 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		usage(void)
{
	ft_putstr("Usage /fractol \"julia : 1\", \"mandelbrot : 2\"");
	ft_putstr("\"burning_ship : 3\", \"burning_buf : 4\", \"cub_buf : 5\",");
	ft_putstr("\"mand_hor : 6\", \"cub_mand : 7\", \"man4 : 8\"\n");
	exit(0);
}

static void		init_fract(t_fract *fract)
{
	if (fract->fract_v == 0)
		init_fract_jul(fract);
	if (fract->fract_v == 1)
		init_fract_man(fract);
	if (fract->fract_v == 2)
		init_fract_bur(fract);
	if (fract->fract_v == 3)
		init_fract_burbuf(fract);
	if (fract->fract_v == 4)
		init_cub_buf(fract);
	if (fract->fract_v == 5)
		init_man_hor(fract);
	if (fract->fract_v == 6)
		init_cub_mand(fract);
	if (fract->fract_v == 7)
		init_man4(fract);
}

void			choosen(char *av, t_fract *fract)
{
	fract->fract_v = 10;
	if (ft_strcmp(av, "julia") == 0 || (ft_strcmp(av, "1") == 0))
		fract->fract_v = 0;
	if (ft_strcmp(av, "mandelbrot") == 0 || (ft_strcmp(av, "2") == 0))
		fract->fract_v = 1;
	if (ft_strcmp(av, "burning_ship") == 0 || (ft_strcmp(av, "3") == 0))
		fract->fract_v = 2;
	if (ft_strcmp(av, "burning_buf") == 0 || (ft_strcmp(av, "4") == 0))
		fract->fract_v = 3;
	if (ft_strcmp(av, "cub_buf") == 0 || (ft_strcmp(av, "5") == 0))
		fract->fract_v = 4;
	if (ft_strcmp(av, "mand_hor") == 0 || (ft_strcmp(av, "6") == 0))
		fract->fract_v = 5;
	if (ft_strcmp(av, "cub_mand") == 0 || (ft_strcmp(av, "7") == 0))
		fract->fract_v = 6;
	if (ft_strcmp(av, "man4") == 0 || (ft_strcmp(av, "8") == 0))
		fract->fract_v = 7;
	if (fract->fract_v > 7 || fract->fract_v < 0)
		usage();
	init_fract(fract);
}

void			mlx_win_init(t_fract *fract)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, W, H, "Fractol kek");
}

int				main(int ac, char **av)
{
	t_fract *fract;
	pid_t	pid;

	pid = 1;
	if (ac < 2 || ac > 3)
	{
		ft_putstr("Wrong number of arguments\n");
		usage();
	}
	if (ac == 3)
		pid = fork();
	fract = (t_fract*)ft_memalloc(1 * sizeof(t_fract) + 1);
	mlx_win_init(fract);
	choosen(av[pid == 0 ? 2 : 1], fract);
	draw(fract);
	mlx_hook(fract->win, 2, 2, user_hook, fract);
	mlx_hook(fract->win, 6, 0, mouse_hook, fract);
	mlx_mouse_hook(fract->win, mouse_scr, fract);
	mlx_loop(fract);
	return (0);
}
