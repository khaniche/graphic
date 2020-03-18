/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:00:09 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/30 18:00:13 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static t_gnl	*multfd(t_gnl **value, int fd)
{
	t_gnl	*first;
	t_gnl	*tmp;

	if (!*value)
	{
		(*value) = (t_gnl*)ft_memalloc(sizeof(t_gnl));
		(*value)->fd = fd;
	}
	first = *value;
	while (value)
	{
		if ((*value)->fd == fd)
			break ;
		if ((*value)->next == NULL)
		{
			(*value)->next = (t_gnl*)ft_memalloc(sizeof(t_gnl));
			(*value) = (*value)->next;
			(*value)->fd = fd;
			break ;
		}
		(*value) = (*value)->next;
	}
	tmp = *value;
	*value = first;
	return (tmp);
}

static int		get_line(t_gnl **lst, char **str, int ret)
{
	char	*i;
	t_gnl	*list;
	char	*res;

	i = NULL;
	list = *lst;
	if (ret < 0)
		return (-1);
	if (ret == 0 && (list->value == NULL || list->value[0] == '\0'))
		return (0);
	if ((i = ft_strchr(list->value, '\n')) != NULL)
	{
		(*str) = ft_strsub(list->value, 0, i - (list->value));
		res = list->value;
		list->value = ft_strdup(i + 1);
		free(res);
	}
	else
	{
		(*str) = ft_strdup(list->value);
		ft_strdel(&list->value);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*value;
	t_gnl			*list;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	if (BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	*line = 0;
	list = multfd(&value, fd);
	while ((ret = read(list->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!list->value)
			(list->value) = ft_strnew(1);
		tmp = list->value;
		list->value = ft_strjoin(tmp, buf);
		free(tmp);
		if (check(buf) != (-1))
			break ;
	}
	return (get_line(&list, line, ret));
}
