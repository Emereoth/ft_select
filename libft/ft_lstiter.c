/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 13:46:17 by acottier          #+#    #+#             */
/*   Updated: 2015/12/17 18:30:27 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*tmp;

	if (!lst || !f)
		return ;
	ptr = lst;
	tmp = lst->next;
	while (tmp != NULL)
	{
		f(ptr);
		ptr = tmp;
		tmp = tmp->next;
	}
	f(ptr);
}
