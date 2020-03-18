/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 23:33:24 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/08 23:33:27 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char	*first;

	first = s1;
	while (*first != '\0')
		first++;
	while (*s2)
		*first++ = *s2++;
	*first = '\0';
	return (s1);
}
