/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:53:16 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/16 18:53:16 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnchr(const char *s, int c, int n)
{
	char	*str;

	str = (char*)s;
	while (*str != c && n > 0)
	{
		if (*str == '\0')
			return (NULL);
		str++;
		n--;
	}
	return (str);
}
