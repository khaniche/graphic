/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:09:16 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/08 14:03:07 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)str;
	while (i < n)
	{
		res[i] = (unsigned int)c;
		i++;
	}
	return (res);
}
