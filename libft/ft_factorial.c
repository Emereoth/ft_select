/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:29:39 by acottier          #+#    #+#             */
/*   Updated: 2016/01/15 06:45:21 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_factorial(int x)
{
	int i;
	int res;

	i = 0;
	res = 1;
	if (x == 0)
		return (0);
	if (x < 0)
	{
		i = -1;
		while (i != x)
		{
			i--;
			res = res * i;
		}
		return (res);
	}
	i = 1;
	while (i != x)
	{
		i++;
		res = res * i;
	}
	return (res);
}
