/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mklist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:47:05 by acottier          #+#    #+#             */
/*   Updated: 2016/09/22 12:51:17 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void			kill_blanks(t_elem *lst)
{
	t_elem	*start;
	t_elem	*next;
	int		over;

	over = 2;
	start = lst;
	while (lst)
	{
		if (lst->null == 1)
		{
			lst->prev->next = NULL;
			next = lst->next;
			free(lst);
		}
		if (lst)
			lst = lst->next;
		else
			lst = next;
	}
}

t_elem			*del_elem(t_elem *lst, t_info *info, int *over)
{
	t_elem	*cur;

	kill_blanks(lst);
	cur = to_cursor(lst);
	free(cur->name);
	if (cur->next)
	{
		cur->next->current = 1;
		cur->next->prev = cur->prev;
	}
	if (cur->prev)
	{
		if (!(cur->next))
			to_start(lst)->current = 1;
		cur->prev->next = cur->next;
	}
	else
		lst = lst->next;
	if (!(cur->next) && !(cur->prev) && *over != 2)
		quit_all(lst, info, over, NULL);
	free(cur);
	tputs(tgetstr("cl", 0), 1, ft_useless);
	return (lst);
}

t_elem			*add_null_elem(t_elem *lst)
{
	t_elem	*res;

	res = (t_elem *)malloc(sizeof(t_elem));
	res->name = NULL;
	res->biggest = lst->biggest;
	res->index = lst->index + 1;
	res->col = lst->col + 1;
	res->li = lst->li;
	res->null = 1;
	res->prev = lst;
	lst->next = res;
	res->next = NULL;
	return (res);
}

static	t_elem	*add_elem(char *name, t_elem *lst, int index)
{
	t_elem	*res;

	res = (t_elem *)malloc(sizeof(t_elem));
	res->name = ft_strdup(name);
	res->index = index;
	res->null = 0;
	res->mod = 0;
	if (lst)
		lst->next = res;
	res->prev = lst;
	res->next = NULL;
	return (res);
}

t_elem			*mk_elem_list(char **argv)
{
	int		i;
	t_elem	*lst;

	lst = NULL;
	i = 1;
	while (argv[i] != NULL)
	{
		lst = add_elem(argv[i], lst, i);
		i++;
	}
	while (lst->prev)
		lst = lst->prev;
	lst->current = 1;
	return (lst);
}
