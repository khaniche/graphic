/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:10:51 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/09 21:10:55 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				min;
	unsigned long	res;

	min = 1;
	res = 0;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			min = -1;
		str++;
	}
	while ((*str) || (*str < 48) || (*str > 57))
	{
		if (*str < 48 || *str > 57)
			return (res * min);
		else
			res = res * 10 + (unsigned long)(*str - 48);
		if (res >= 9223372036854775807)
			return (min == -1 ? 0 : -1);
		str++;
	}
	return (res * min);
}
