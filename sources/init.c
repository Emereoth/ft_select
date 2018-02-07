/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 15:42:48 by acottier          #+#    #+#             */
/*   Updated: 2016/10/03 14:12:09 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int	term_init(t_info **info)
{
	if (!(*info))
	{
		*info = (t_info *)malloc(sizeof(t_info));
		(*info)->name = getenv("TERM");
	}
	if (tgetent(NULL, (*info)->name) == ERR)
		return (1);
	if (tcgetattr(0, &(*info)->term) == -1)
		return (1);
	if (tcgetattr(0, &(*info)->save) == -1)
		return (1);
	(*info)->srchprompt = 0;
	(*info)->sleep = 0;
	(*info)->fd = open(ttyname(0), O_WRONLY);
	(*info)->col = tgetnum("co");
	(*info)->li = tgetnum("li");
	return (0);
}
