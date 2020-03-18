/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:53:36 by khaniche          #+#    #+#             */
/*   Updated: 2019/04/19 11:53:43 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	tetrimino_pusher(char **map, t_point *point, t_tetri *tetr)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[point->y + tetr->y[i]][point->x +
			tetr->x[i]] = tetr->letter;
		i++;
	}
}

static	int		space_checker(char **map, t_point *point,
	t_tetri *tetr, int size)
{
	int i;

	i = 0;
	if (!(tetr->l + point->x < size && tetr->h +
		point->y < size))
		return (0);
	else
		while (i < 4)
		{
			if (map[point->y + tetr->y[i]][point->x +
				tetr->x[i]] != '.')
				return (0);
			i++;
		}
	return (1);
}

static	void	coordinat_changer(t_point *point, int size)
{
	if (point->x == size - 1)
	{
		point->y = point->y + 1;
		point->x = 0;
	}
	else
		point->x = point->x + 1;
}

static	void	tetrimino_deleter(t_tetri *tetr, char **map, int size)
{
	int		y;
	int		x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == tetr->letter)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

int				b_tracker(char **map, t_tetri *tetr, t_point *point,
int size)
{
	t_point coords;

	if (space_checker(map, point, tetr, size))
	{
		tetrimino_pusher(map, point, tetr);
		if (tetr->next)
		{
			coords.y = 0;
			coords.x = 0;
			if (!b_tracker(map, tetr->next, &coords, size))
			{
				tetrimino_deleter(tetr, map, size);
				coordinat_changer(point, size);
				return (b_tracker(map, tetr, point, size));
			}
		}
		return (1);
	}
	if (point->y == size - 1 && point->x == size - 1)
		return (0);
	coordinat_changer(point, size);
	return (b_tracker(map, tetr, point, size));
}
