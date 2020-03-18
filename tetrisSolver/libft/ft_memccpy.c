/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:45:52 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/08 14:45:54 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	int				i;

	i = 0;
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (n--)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == (unsigned char)c)
			return (cdst + i + 1);
		i++;
	}
	return (NULL);
}
