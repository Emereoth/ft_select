/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 09:29:54 by acottier          #+#    #+#             */
/*   Updated: 2016/09/01 18:22:40 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_err(char *str)
{
	int		length;

	length = 0;
	while (str[length])
		length++;
	write(2, str, length);
	write(2, "\n", 1);
}
