/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:43:20 by acottier          #+#    #+#             */
/*   Updated: 2016/09/27 15:05:26 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int			main(int argc, char **argv)
{
	t_elem				*lst;
	t_info				*info;

	info = NULL;
	if (argc > 1)
	{
		if (term_init(&info) == 1)
			error(NULL, 0);
		else
		{
			sig_handler();
			ft_memcpy(&(info->save), &(info->term), sizeof(info->save));
			lst = mk_elem_list(argv);
			info->lst = lst;
			backup(info, 0);
			shell_modify(&(info->term), 1);
			tputs(tgetstr("cl", 0), 1, ft_useless);
			disp_settings(lst, info);
			commands(lst, info);
			shell_modify(&(info->save), 0);
			close(info->fd);
		}
	}
	else
		ft_putendl_err("No arguments found.");
}
