/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:47:46 by khaniche          #+#    #+#             */
/*   Updated: 2019/04/26 14:47:50 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*new_ary(size_t len)
{
	t_ary	*arry;

	arry = malloc(sizeof(t_ary));
	arry->ptr = malloc(sizeof(void*) * len);
	arry->len = 0;
	arry->max = len;
	return (arry);
}

void	*push(void *arry, void *ptr)
{
	t_ary	*ary;
	void	**tmp;

	ary = arry;
	if (ary->len >= ary->max)
	{
		ary->max *= 2;
		tmp = malloc(sizeof(void*) * ary->max);
		ft_memcpy(tmp, ary->ptr, (ary->len * sizeof(void*)));
		free(ary->ptr);
		ary->ptr = tmp;
	}
	return (ary->ptr[ary->len++] = ptr);
}

void	*free_ary(void *arry)
{
	if (arry)
		free(((t_ary*)arry)->ptr);
	free(arry);
	return (0);
}
