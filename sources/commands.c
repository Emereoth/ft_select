/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:13:25 by acottier          #+#    #+#             */
/*   Updated: 2016/10/03 16:56:55 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static	t_elem	*side_movement(t_elem *lst, int key, t_elem *cur)
{
	cur->current = 0;
	if (key == L_ARR)
	{
		if (cur->prev)
			cur = cur->prev;
		else
			cur = to_end(cur);
	}
	else if (key == R_ARR)
	{
		if (cur->next && cur->next->null == 0)
			cur = cur->next;
		else
			cur = to_start(cur);
	}
	cur->current = 1;
	return (lst);
}

static	t_elem	*vert_movement(int key, t_elem *lst, t_elem *cur, t_info *info)
{
	cur->current = 0;
	(info->max_line == 1 && key == U_ARR) ? (cur = to_start(lst)) : 0;
	(info->max_line == 1 && key == D_ARR) ? (cur = to_end(lst)) : 0;
	if (key == U_ARR && info->max_line > 1)
	{
		if (cur->li == 1)
		{
			if (to_coords(lst, cur, info->max_line, cur->col) == NULL)
				cur = to_coords(lst, cur, info->max_line - 1, cur->col);
			else
				cur = to_coords(lst, cur, info->max_line, cur->col);
		}
		else
			cur = to_coords(lst, cur, cur->li - 1, cur->col);
	}
	if (key == D_ARR && info->max_line > 1)
	{
		if (to_coords(lst, cur, cur->li + 1, cur->col) == NULL)
			cur = to_coords(lst, cur, 1, cur->col);
		else
			cur = to_coords(lst, cur, cur->li + 1, cur->col);
	}
	cur->current = 1;
	return (lst);
}

static	t_elem	*selection(int key, t_elem *lst, t_elem *cur)
{
	if (key == SPACE)
	{
		if (cur->selected == 0)
			cur->selected = 1;
		else
			cur->selected = 0;
		cur->current = 0;
		if (cur->next && cur->next->null == 0)
			cur->next->current = 1;
		else
			to_start(lst)->current = 1;
	}
	else if (key == CTRL_A || key == CTRL_D)
		return (all_selection(key, lst));
	else if (key == L_SEL || key == R_SEL || key == U_SEL || key == D_SEL)
		return (row_selection(key, lst, cur));
	else if (key == L_CHU || key == R_CHU || key == U_CHU || key == D_CHU)
		return (chunk_selection(key, lst, cur));
	else if (key == MOD_SEL)
		return (mod_selection(lst, cur));
	return (lst);
}

static	t_elem	*treat_input(int key, t_elem *lst, t_info *info, int *over)
{
	if (key == SEARCH)
		return (search(lst, info, over, ft_strnew(1)));
	else if (key == L_ARR || key == R_ARR)
		return (side_movement(lst, key, to_cursor(lst)));
	else if (key == U_ARR || key == D_ARR)
		return (vert_movement(key, lst, to_cursor(lst), info));
	else if (key == SPACE || key == U_SEL || key == D_SEL || key == L_SEL
			|| key == R_SEL || key == MOD_SEL || key == U_CHU
			|| key == D_CHU || key == L_CHU || key == R_CHU
			|| key == CTRL_A || key == CTRL_D)
		return (selection(key, lst, to_cursor(lst)));
	else if (key == DEL || key == BACKSPACE)
		return (del_elem(lst, info, over));
	else if (key == ENTER)
		return (validation(lst, info, over));
	else if (key == ESC)
		return (quit_all(lst, info, over, NULL));
	else
		return (to_start(lst));
}

void			commands(t_elem *lst, t_info *info)
{
	int		over;
	char	*buff[5];

	over = 0;
	*(int *)buff = 0;
	while (over == 0)
	{
		ft_memset(buff, 0, 5);
		lst = to_start(lst);
		read(0, buff, 4);
		if (info->sleep == 0)
		{
			tputs(tgoto(tgetstr("cm", 0), 0, 0), 1, ft_useless);
			lst = treat_input(*(int *)buff, lst, info, &over);
			if (over == 0)
				disp_settings(lst, info);
		}
	}
}
