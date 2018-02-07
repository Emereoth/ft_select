/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:17:29 by acottier          #+#    #+#             */
/*   Updated: 2016/09/19 12:17:46 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabsize(char **my_tab)
{
	char	*cursor;
	int		res;

	res = 0;
	cursor = my_tab[0];
	while (cursor != NULL)
	{
		res++;
		cursor = my_tab[res];
	}
	return (res);
}
