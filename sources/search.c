/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:40:11 by acottier          #+#    #+#             */
/*   Updated: 2016/10/03 14:13:35 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static	char	*str_update(char res[5], char *stock)
{
	char	*swap;

	swap = ft_strjoin(stock, res);
	free(stock);
	stock = ft_strdup(swap);
	free(swap);
	return (stock);
}

static	t_elem	*find(t_elem *lst, char *stock, char res[5])
{
	t_elem	*cursor;
	char	**commands;
	int		i;

	i = -1;
	tputs(tgetstr("cl", 0), 1, ft_useless);
	if (*(int *)res == SEARCH)
	{
		(stock) ? (free(stock)) : 0;
		return (to_start(lst));
	}
	commands = ft_strsplit(stock, ' ');
	while (commands[++i])
	{
		cursor = to_start(lst);
		while (cursor)
		{
			if (ft_strstr(cursor->name, commands[i]) != 0)
				cursor->selected = 1;
			cursor = cursor->next;
		}
	}
	free(stock);
	ft_freetab(commands);
	return (to_start(lst));
}

t_elem			*search(t_elem *lst, t_info *info, int *over, char *stock)
{
	char	res[5];

	info->srchprompt = 2;
	disp_settings(lst, info);
	ft_putstr("-----\nSearching string : ");
	while (*(int *)res != 10 && *(int *)res != 27 && *(int *)res != SEARCH)
	{
		ft_memset(res, 0, 5);
		read(0, res, 4);
		if (*(int *)res == 127)
			stock[ft_strlen(stock)] = '\0';
		else
			ft_putstr(res);
		if (*(int *)res != 10)
			stock = str_update(res, stock);
	}
	if (*(int *)res == 27)
		return (quit_all(lst, info, over, stock));
	return (find(lst, stock, res));
}
