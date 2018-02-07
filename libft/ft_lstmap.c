/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:11:27 by acottier          #+#    #+#             */
/*   Updated: 2015/12/18 05:18:09 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*list;
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	start = new;
	if (new && lst && (*f))
	{
		new = (*f)(lst);
		start = new;
		while (lst->next)
		{
			if (!(list = (t_list*)malloc(sizeof(t_list))))
				return (NULL);
			lst = lst->next;
			list = (*f)(lst);
			new->next = list;
			new = new->next;
		}
	}
	return (start);
}
