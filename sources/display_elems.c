/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_elems.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 12:30:26 by acottier          #+#    #+#             */
/*   Updated: 2016/10/03 14:16:05 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static	void		free_list(t_elem *lst)
{
	t_elem	*swap;

	while (lst)
	{
		swap = lst->next;
		free(lst->name);
		free(lst);
		lst = swap;
	}
}

t_elem				*validation(t_elem *lst, t_info *info, int *over)
{
	t_elem	*cur;
	int		first;

	first = 0;
	cur = lst;
	tputs(tgetstr("cl", 0), 1, ft_useless);
	while (cur)
	{
		if (cur->selected == 1 && cur->null == 0)
		{
			if (first == 0)
				first++;
			else
				ft_putchar(' ');
			ft_putstr(cur->name);
		}
		cur = cur->next;
	}
	free_list(lst);
	free(info);
	*over = 1;
	return (NULL);
}

void				display_elems(t_elem *lst, t_info *info)
{
	int		padding;

	while (lst)
	{
		padding = lst->biggest - ft_strlen(lst->name) + 1;
		(lst->current == 1) ? ft_putstr_fd(UL, info->fd) : 0;
		(lst->selected == 1) ? ft_putstr_fd(HI, info->fd) : 0;
		(lst->mod == 1) ? ft_putstr_fd(BO, info->fd) : 0;
		ft_putstr_fd(lst->name, info->fd);
		ft_putstr_fd(NC, info->fd);
		while (padding-- > 0)
			ft_putchar_fd(' ', info->fd);
		if (lst->col == info->max_col)
			ft_putchar_fd('\n', info->fd);
		lst = lst->next;
	}
}
