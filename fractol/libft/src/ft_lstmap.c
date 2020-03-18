/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaniche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:35:27 by khaniche          #+#    #+#             */
/*   Updated: 2018/11/16 16:35:28 by khaniche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*list;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		list->next = f(lst);
		list = list->next;
	}
	list->next = NULL;
	return (new);
}
