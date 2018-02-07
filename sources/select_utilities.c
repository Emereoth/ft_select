/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 15:35:52 by acottier          #+#    #+#             */
/*   Updated: 2016/09/21 15:08:51 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

t_elem		*all_selection(int key, t_elem *lst)
{
	t_elem	*cursor;

	cursor = to_start(lst);
	while (cursor)
	{
		if (key == CTRL_A)
			cursor->selected = 1;
		if (key == CTRL_D)
			cursor->selected = 0;
		cursor = cursor->next;
	}
	return (lst);
}

static	int	sel_or_desel(int key, t_elem *lst, t_elem *cur)
{
	int		res;

	res = 0;
	while (lst)
	{
		if (key == L_SEL && lst->li == cur->li && lst->col < cur->col)
			(lst->selected == 0) ? (res = 1) : 0;
		if (key == R_SEL && lst->li == cur->li && lst->col > cur->col)
			(lst->selected == 0) ? (res = 1) : 0;
		if (key == U_SEL && lst->li < cur->li && lst->col == cur->col)
			(lst->selected == 0) ? (res = 1) : 0;
		if (key == D_SEL && lst->li > cur->li && lst->col == cur->col)
			(lst->selected == 0) ? (res = 1) : 0;
		else if (key == U_CHU && lst->li < cur->li)
			(lst->selected == 0) ? (res = 1) : 0;
		else if (key == D_CHU && lst->li > cur->li)
			(lst->selected == 0) ? (res = 1) : 0;
		else if (key == L_CHU && lst->col < cur->col)
			(lst->selected == 0) ? (res = 1) : 0;
		else if (key == R_CHU && lst->col > cur->col)
			(lst->selected == 0) ? (res = 1) : 0;
		lst = lst->next;
	}
	return (res);
}

t_elem		*row_selection(int key, t_elem *lst, t_elem *cur)
{
	int		select;
	t_elem	*start;

	start = to_start(lst);
	select = sel_or_desel(key, lst, cur);
	while (lst)
	{
		if (key == L_SEL && lst->li == cur->li && lst->col < cur->col)
			lst->selected = select;
		else if (key == R_SEL && lst->li == cur->li && lst->col > cur->col)
			lst->selected = select;
		else if (key == U_SEL && lst->li < cur->li && lst->col == cur->col)
			lst->selected = select;
		else if (key == D_SEL && lst->li > cur->li && lst->col == cur->col)
			lst->selected = select;
		lst = lst->next;
	}
	return (start);
}

t_elem		*chunk_selection(int key, t_elem *lst, t_elem *cur)
{
	int		select;
	t_elem	*start;

	start = to_start(lst);
	select = sel_or_desel(key, lst, cur);
	while (lst)
	{
		if (key == U_CHU && lst->li < cur->li)
			lst->selected = select;
		else if (key == D_CHU && lst->li > cur->li)
			lst->selected = select;
		else if (key == L_CHU && lst->col < cur->col)
			lst->selected = select;
		else if (key == R_CHU && lst->col > cur->col)
			lst->selected = select;
		lst = lst->next;
	}
	return (start);
}
