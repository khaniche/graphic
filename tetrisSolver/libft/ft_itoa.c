/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:54:50 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/12 20:54:51 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lenght(int n)
{
	size_t	size;

	size = 1;
	while (n /= 10)
		size++;
	return (size);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	num;

	len = lenght(n);
	num = n;
	if (n < 0)
	{
		num = n * -1;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = num % 10 + 48;
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
