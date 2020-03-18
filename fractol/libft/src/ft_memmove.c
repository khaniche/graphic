/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:48:01 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/08 15:48:03 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*csrc;
	unsigned char		*cdst;
	size_t				i;

	i = 0;
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	if (cdst > csrc)
	{
		while (len--)
			cdst[len] = csrc[len];
	}
	else if (cdst < csrc)
		ft_memcpy(cdst, csrc, len);
	return (dst);
}
