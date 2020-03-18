/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:29:47 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/10 20:29:48 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	else
	{
		i = 0;
		if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		else
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
		}
	}
	str[i] = '\0';
	return (str);
}
