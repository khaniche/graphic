/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 01:08:45 by khaniche          #+#    #+#             */
/*   Updated: 2019/04/15 01:08:51 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	ne_hvatilo_strok(int *pos, int *check, char *buff,
t_tetri **tetr)
{
	int i;

	i = 0;
	while (buff[i] && check[2] != 4)
	{
		if (buff[i] == '.')
			check[0]++;
		if (buff[i] == '#' && check[1] <= 4)
		{
			pos[check[1]] = i;
			place_x_y(*tetr, i);
			check[1]++;
		}
		if (buff[i++] == '\n')
			check[2]++;
		else
			check[3]++;
	}
}

void			get_h_l(t_tetri *tetr)
{
	int		i;

	while (tetr)
	{
		i = 0;
		while (i < 4)
		{
			if (tetr->y[i] > tetr->y[i + 1])
				tetr->h = tetr->y[i];
			i++;
		}
		i = 0;
		while (i < 4)
		{
			if (tetr->x[i] > tetr->x[i + 1])
				tetr->l = tetr->x[i];
			i++;
		}
		tetr = tetr->next;
	}
}

char			ft_figure(char *buff, int *position)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (count < 4)
	{
		if (*position > 4 && (buff[*position - 5] == '#'))
			i++;
		if (*position < 14 && (buff[*position + 5] == '#'))
			i++;
		if (*position != 0 && buff[*position - 1] != '\n' &&
		buff[*position - 1] == '#')
			i++;
		if (buff[*position + 1] != '\n' && buff[*position + 1] == '#')
			i++;
		count++;
		position++;
	}
	return (i != 6 && i != 8);
}

char			ft_map(char *buff, t_tetri **tetr)
{
	int			pos[4];
	int			check[4];
	static char letter = 'A';

	if ((*tetr)->letter)
	{
		(*tetr)->next = (t_tetri*)ft_memalloc(sizeof(t_tetri));
		*tetr = (*tetr)->next;
	}
	ft_bzero(pos, 16);
	ft_bzero(check, 16);
	(*tetr)->letter = letter++;
	ne_hvatilo_strok(pos, check, buff, tetr);
	if (check[1] == 4 && check[0] == 12 && check[2] == 4 && check[3] == 16)
		return (ft_figure(buff, pos));
	return (1);
}

char			**ft_read(int fd, t_tetri *tetr)
{
	char	**buff;
	int		i;

	i = 0;
	if (!(buff = (char**)ft_memalloc(sizeof(char*) * (26 + 1))))
		return (NULL);
	while (i <= 26)
	{
		if (!(buff[i] = ft_strnew(21)))
			return (NULL);
		if (!(read(fd, buff[i], 21)))
			return (buff);
		if (ft_map(buff[i], &tetr))
			return (NULL);
		i++;
		g_n += 1;
	}
	return (NULL);
}
