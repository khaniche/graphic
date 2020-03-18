/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:11:37 by khaniche          #+#    #+#             */
/*   Updated: 2019/06/14 14:11:39 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error(char *str)
{
	ft_putstr(str);
	exit(-1);
}

t_split		*split_dva_blya(char *str, char *str1)
{
	char	*beg;
	t_split	*res;

	if (!*str)
		return (0);
	while (*str && ft_strchr(str1, *str))
		str++;
	res = new_ary(1);
	while (*str)
	{
		beg = str;
		while (*str && !ft_strchr(str1, *str))
			str++;
		push(res, ft_memcpy(ft_memalloc(sizeof(char) *
			(str - beg + 1)), beg, str - beg));
		while (*str && ft_strchr(str1, *str))
			str++;
	}
	return (res);
}

t_point		*get_c(size_t y, t_split *line, t_fdf *fdf)
{
	size_t	i;
	t_point	*res;

	if (!(res = malloc(sizeof(t_point) * line->len)))
		error("Invalid file");
	i = -1;
	while (++i < line->len)
	{
		res[i].x = (double)i;
		res[i].y = (double)y;
		res[i].z = (double)ft_atoi(line->str[i]);
		res[i].s_x = (double)i;
		res[i].s_y = (double)y;
		res[i].s_z = (double)ft_atoi(line->str[i]);
		max_val(res[i].z, fdf);
		if (res[i].z >= 999999 || res[i].z <= -999999)
			error("Incorrect Z - value\n");
		free(line->str[i]);
	}
	return (res);
}

void		read_map(int fd, t_fdf *fdf)
{
	t_points	*map;
	t_split		*c;
	char		*line;

	map = new_ary(1);
	while ((get_next_line(fd, &line)) > 0)
		if (*line)
		{
			c = split_dva_blya(line, "\t ");
			if ((fdf->max.x && (double)fdf->max.x != c->len) || (c->len == 0))
				error("Invalid map");
			else
				fdf->max.x = c->len;
			if (c->len > 1000)
				error("Big size of values");
			push(map, get_c(map->len, c, fdf));
			free_ary(c);
			free(line);
		}
		else
			error("error");
	fdf->max.y = map->len;
	fdf->point = map->point;
	free(map);
}

int			main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;

	if (argc != 2)
		error("Wrong number of arguments");
	check_av(argv);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		error("Can't open file");
	init(&fdf);
	read_map(fd, &fdf);
	set_default(&fdf);
	projection(&fdf);
	draw(&fdf);
	mlx_hook(fdf.win, 2, 2, user_hook, &fdf);
	mlx_loop(fdf.mlx);
}
