/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:06:08 by acottier          #+#    #+#             */
/*   Updated: 2015/12/18 05:17:45 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	t_list *ptr2;

	ptr = *alst;
	ptr2 = (*alst)->next;
	while (ptr2 != NULL)
	{
		del(ptr->content, ptr->content_size);
		free(ptr);
		ptr = ptr2;
		ptr2 = ptr2->next;
	}
	del(ptr->content, ptr->content_size);
	free(ptr);
	*alst = NULL;
}
