/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:20:15 by acottier          #+#    #+#             */
/*   Updated: 2016/10/03 16:57:22 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_elem		*to_cursor(t_elem *lst)
{
	t_elem	*res;

	res = lst;
	while (res)
	{
		if (res->current == 1)
			return (res);
		res = res->next;
	}
	error(NULL, 4);
	return (NULL);
}

t_elem		*to_coords(t_elem *lst, t_elem *cur, int li, int col)
{
	t_elem	*res;

	res = lst;
	while (res)
	{
		if (res->li == li && res->col == col && res->null == 0)
		{
			cur->current = 0;
			res->current = 1;
			return (res);
		}
		res = res->next;
	}
	return (NULL);
}

t_elem		*to_end(t_elem *cur)
{
	while (cur->next && cur->next->null == 0)
		cur = cur->next;
	return (cur);
}

t_elem		*to_start(t_elem *cur)
{
	while (cur->prev)
		cur = cur->prev;
	return (cur);
}

t_elem		*quit_all(t_elem *lst, t_info *info, int *over, char *stock)
{
	t_elem	*swap;

	if (stock)
		free(stock);
	free(info);
	while (lst)
	{
		swap = lst->next;
		free(lst->name);
		free(lst);
		lst = swap;
	}
	*over = -1;
	tputs(tgetstr("cl", 0), 1, ft_useless);
	return (NULL);
}
