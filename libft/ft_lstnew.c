/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:47:56 by acottier          #+#    #+#             */
/*   Updated: 2016/04/07 14:31:54 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;
	void	*ptr2;

	if (!(ptr = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	else
	{
		if (!(ptr2 = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(ptr2, content, content_size);
		ptr->content = ptr2;
		ptr->content_size = content_size;
	}
	ptr->next = NULL;
	return (ptr);
}
