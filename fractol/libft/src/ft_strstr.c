/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:03:24 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/17 23:27:37 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int count;
	int len;

	i = 0;
	count = 0;
	len = 0;
	while (needle[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (needle[count] == haystack[i + count])
		{
			if (count == len - 1)
				return ((char *)haystack + i);
			count++;
		}
		count = 0;
		i++;
	}
	return (0);
}
