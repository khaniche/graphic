/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:38:55 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/09 15:38:59 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*first;
	size_t	i;

	i = -1;
	first = s1;
	while (*first != '\0')
		first++;
	while (*s2 && ++i < n)
		*first++ = *s2++;
	*first = '\0';
	return (s1);
}
