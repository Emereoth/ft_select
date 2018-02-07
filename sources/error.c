/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 15:38:06 by acottier          #+#    #+#             */
/*   Updated: 2016/09/09 15:30:59 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	error(char *str, int errnum)
{
	(void)str;
	if (errnum == 0)
		ft_putendl_err("termios struct init failed.");
	else if (errnum == 1)
		ft_putendl_err("Screen too small.");
	else if (errnum == 2)
		ft_putendl_err("Shell modify failed.");
	else if (errnum == 3)
		ft_putendl_err("Input read error, terminating.");
	else if (errnum == 4)
		ft_putendl_err("Couldn't find current element.");
	else if (errnum == 5)
		ft_putendl_err("Error while moving to the right.");
}
