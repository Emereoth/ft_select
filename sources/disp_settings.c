/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:09:26 by acottier          #+#    #+#             */
/*   Updated: 2016/09/21 16:07:00 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static	void	null_padding(t_elem *lst, int nb)
{
	t_elem	*link;

	link = NULL;
	while (lst->next)
		lst = lst->next;
	while (nb > 0)
	{
		lst = add_null_elem(lst);
		nb--;
	}
}

void			list_padding(t_elem *lst, t_info *info)
{
	int		max_col;

	max_col = info->col / (lst->biggest + 1);
	while (lst)
	{
		if (!lst->next)
		{
			if (lst->col < max_col)
				null_padding(lst, max_col - lst->col);
		}
		lst = lst->next;
	}
}

static	void	assign_coords(t_elem *lst, int max_col)
{
	int		line_pos;
	int		col_pos;

	line_pos = 1;
	col_pos = 1;
	while (lst)
	{
		if (col_pos > max_col)
		{
			col_pos = 1;
			line_pos++;
		}
		lst->li = line_pos;
		lst->col = col_pos;
		col_pos++;
		lst = lst->next;
	}
}

static	int		check_size(t_elem *lst, t_elem *cursor, t_info *info, int total)
{
	int		biggest;

	biggest = 0;
	while (cursor)
	{
		total++;
		if ((int)ft_strlen(cursor->name) > biggest)
			biggest = (int)ft_strlen(cursor->name);
		cursor = cursor->next;
	}
	cursor = lst;
	while (cursor)
	{
		cursor->biggest = biggest;
		cursor = cursor->next;
	}
	info->max_col = info->col / (biggest + 1);
	info->max_line = (to_end(lst)->index / info->max_col) + info->srchprompt;
	if (to_end(lst)->index % info->max_col != 0)
		info->max_line++;
	(info->max_line == 0) ? (info->max_line = 1) : 0;
	if (total > info->max_col * info->li)
		return (1);
	return (0);
}

void			disp_settings(t_elem *lst, t_info *info)
{
	info->max_col = 0;
	if (check_size(lst, lst, info, 0) == 1)
	{
		tputs(tgetstr("cl", 0), 1, ft_useless);
		error(NULL, 1);
	}
	else
	{
		assign_coords(lst, info->max_col);
		list_padding(lst, info);
		info->lst = to_start(lst);
		display_elems(lst, info);
	}
}
