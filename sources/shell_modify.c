/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_modify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 13:01:45 by acottier          #+#    #+#             */
/*   Updated: 2016/09/26 18:33:42 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int			ft_useless(int c)
{
	return (write(0, &c, 1));
}

void		shell_modify(struct termios *term, int create)
{
	if (create == 1)
	{
		term->c_lflag &= ~(ICANON);
		term->c_lflag &= ~(ECHO);
		term->c_cc[VMIN] = 1;
		term->c_cc[VTIME] = 0;
		tputs(tgetstr("vi", 0), 1, ft_useless);
		if (tcsetattr(0, TCSADRAIN, term) == -1)
			error(NULL, 2);
	}
	else
	{
		tputs(tgetstr("ve", 0), 1, ft_useless);
		if (tcsetattr(0, TCSADRAIN, term) == -1)
			error(NULL, 2);
	}
}
