/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:55:36 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/09 20:55:38 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;

	if (*needle == '\0')
		return ((char *)haystack);
	count = ft_strlen(needle);
	while (*haystack != '\0' && count <= len--)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, count) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
