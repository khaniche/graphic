/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:41:41 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/09 17:41:43 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (*(dst + i) && i < size)
		i++;
	while (*(src + j) && ((i + j + 1) < size))
	{
		*(dst + (j + i)) = *(src + j);
		j++;
	}
	if (i != size)
		dst[j + i] = '\0';
	return (i + ft_strlen(src));
}
