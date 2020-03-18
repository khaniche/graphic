/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:00:28 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/12 15:33:35 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_put_word(char const *s, char c, int *i)
{
	char	*word;
	int		d;

	d = 0;
	while (s[*i] == c)
		(*i)++;
	if (!(word = (char*)malloc(sizeof(char) * ft_strlen(s))))
		return (NULL);
	while (s[*i] != c && s[*i])
	{
		word[d] = s[*i];
		d++;
		(*i)++;
	}
	word[d] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	int		count;
	char	**res;
	int		i;
	int		last_pos;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	if (!(res = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	if (s[0] == '\0')
	{
		res[0] = NULL;
		return (res);
	}
	last_pos = 0;
	while (i < count)
	{
		res[i] = ft_put_word(s, c, &last_pos);
		i++;
	}
	res[i] = NULL;
	return (res);
}
