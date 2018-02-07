/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:27:19 by acottier          #+#    #+#             */
/*   Updated: 2016/10/03 14:13:06 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static	void	resize(t_info *info)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	info->col = win.ws_col;
	info->li = win.ws_row;
}

t_info			*backup(t_info *to_save, int op)
{
	static	t_info	*stock;

	if (op == 0)
		stock = to_save;
	return (stock);
}

void			suspend(int sig_id, t_info *info)
{
	char	c;

	if (sig_id == 18)
	{
		tputs(tgetstr("cl", 0), 1, ft_useless);
		info->sleep = 1;
		c = info->save.c_cc[VSUSP];
		ioctl(0, TIOCSTI, &c);
		shell_modify(&info->save, 0);
		signal(sig_id, SIG_DFL);
	}
	else
	{
		signal(18, sig_call);
		tputs(tgetstr("cl", 0), 1, ft_useless);
		info->sleep = 0;
		shell_modify(&info->term, 1);
		resize(info);
		disp_settings(info->lst, info);
	}
}

void			sig_call(int sig_id)
{
	t_info	*info;

	info = backup(NULL, 1);
	if (sig_id == 28)
	{
		resize(info);
		tputs(tgetstr("cl", 0), 1, ft_useless);
		disp_settings(info->lst, info);
	}
	else if (sig_id == 18 || sig_id == 19)
		suspend(sig_id, info);
	else
		signal(sig_id, SIG_IGN);
}

void			sig_handler(void)
{
	int		sig_id;

	sig_id = 1;
	while (sig_id < 32)
	{
		signal(sig_id, sig_call);
		sig_id++;
	}
}
