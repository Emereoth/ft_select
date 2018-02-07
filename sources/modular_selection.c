/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modular_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:29:45 by acottier          #+#    #+#             */
/*   Updated: 2016/10/03 16:55:20 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static	t_coord	*get_coord(t_elem *start, t_elem *end)
{
	t_coord		*res;

	res = (t_coord *)malloc(sizeof(t_coord));
	if (start->li > end->li)
	{
		res->minli = end->li;
		res->maxli = start->li;
	}
	else
	{
		res->minli = start->li;
		res->maxli = end->li;
	}
	if (start->col > end->col)
	{
		res->mincol = end->col;
		res->maxcol = start->col;
	}
	else
	{
		res->mincol = start->col;
		res->maxcol = end->col;
	}
	return (res);
}

static	int		selection(t_elem *lst, t_elem *start, t_elem *end, int turn)
{
	int		select;
	t_coord	*coord;

	if (turn == 0)
		select = 0;
	else
		select = selection(lst, start, end, 0);
	coord = get_coord(start, end);
	while (lst)
	{
		if (lst->li >= coord->minli && lst->li <= coord->maxli
				&& lst->col >= coord->mincol && lst->col <= coord->maxcol)
		{
			if (turn == 0 && lst->selected == 0)
			{
				select = 1;
				break ;
			}
			else if (turn == 1)
				lst->selected = select;
		}
		lst = lst->next;
	}
	free(coord);
	return ((turn == 0 ? select : 0));
}

static	void	walkthrough(t_elem *lst)
{
	t_elem	*start;
	t_elem	*end;
	t_elem	*cursor;

	start = NULL;
	end = NULL;
	cursor = lst;
	while (cursor)
	{
		if (cursor->mod == 1)
		{
			if (!start)
				start = cursor;
			else
				end = cursor;
		}
		if (end != NULL)
			break ;
		cursor = cursor->next;
	}
	start->mod = 0;
	end->mod = 0;
	selection(lst, start, end, 1);
}

t_elem			*mod_selection(t_elem *lst, t_elem *cur)
{
	int		selection;
	t_elem	*cursor;

	selection = 0;
	cursor = lst;
	if (to_cursor(lst)->mod == 1)
	{
		to_cursor(lst)->mod = 0;
		return (to_start(lst));
	}
	while (cursor)
	{
		if (cursor->mod == 1)
			selection = 1;
		cursor = cursor->next;
	}
	cur->mod = 1;
	if (selection == 1)
		walkthrough(lst);
	return (to_start(lst));
}
