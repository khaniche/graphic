/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 01:12:05 by khaniche          #+#    #+#             */
/*   Updated: 2019/04/15 01:12:09 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		error_message(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage : fillit fillit_file\n");
		exit(1);
	}
}

char			**solver(char **map, t_tetri *tetr)
{
	int		size;
	t_point point;

	point.x = 0;
	point.y = 0;
	size = sqrt_size(g_n);
	map = alloc_map(size);
	while (!b_tracker(map, tetr, &point, size))
	{
		free_map(map);
		map = alloc_map(++size);
		ft_bzero(&point, sizeof(t_point));
	}
	return (map);
}

int				main(int argc, char *argv[])
{
	int			fd;
	char		**str;
	char		**map;
	t_tetri		*tetr;

	map = NULL;
	tetr = (t_tetri*)ft_memalloc(sizeof(t_tetri));
	error_message(argc);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit(-1);
	if (!(str = ft_read(fd, tetr)) || str[0][0] == '\0' || str[g_n - 1][21 - 1])
	{
		ft_putstr("error\n");
		exit(-1);
	}
	cut_tetr(tetr);
	get_h_l(tetr);
	map = solver(map, tetr);
	while (*map)
		ft_putendl(*(map++));
	close(fd);
	return (0);
}
