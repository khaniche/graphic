/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:58:36 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/16 22:58:39 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **c)
{
	int i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		c[i] = 0;
		i++;
	}
	free(c);
	c = 0;
}
