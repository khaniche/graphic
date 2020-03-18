/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:18:45 by khaniche          #+#    #+#             */
/*   Updated: 2019/04/16 19:18:48 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		sqrt_size(int size)
{
	int i;

	i = 0;
	while (i * i < (size * 4))
		i++;
	return (i);
}

void	place_x_y(t_tetri *tetr, int i)
{
	static int	k = -1;

	tetr->x[++k] = i % 5;
	tetr->y[k] = i / 5;
	if (k == 3)
		k = -1;
}

void	cut_tetr(t_tetri *tetr)
{
	int i;

	while (tetr)
	{
		i = 0;
		if (tetr->y[0] > 0)
			while (i < 4)
			{
				tetr->y[i] = tetr->y[i] - 1;
				i++;
				if (tetr->y[0] > 0 && i == 4)
					i = 0;
			}
		i = 0;
		if (tetr->x[0] && tetr->x[1] && tetr->x[2] && tetr->x[3])
			while (i < 4)
			{
				tetr->x[i] = tetr->x[i] - 1;
				i++;
				if (tetr->x[0] && tetr->x[1] && tetr->x[2] && tetr->x[3]
					&& i == 4)
					i = 0;
			}
		tetr = tetr->next;
	}
}

char	**alloc_map(int size)
{
	char	**res;
	int		i;

	if (!(res = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (size > i)
	{
		res[i] = (char*)malloc(sizeof(char) * (size));
		res[i] = ft_memset(res[i], '.', size);
		res[i][size] = '\0';
		i++;
	}
	res[size] = NULL;
	return (res);
}

void	free_map(char **map)
{
	while (*map)
		free(*map++);
}
