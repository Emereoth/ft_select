/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:17:50 by acottier          #+#    #+#             */
/*   Updated: 2015/12/11 05:41:31 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		res;

	i = 0;
	neg = 0;
	res = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n'))
		i++;
	if (str[i] == '-')
	{
		res = -res;
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	i--;
	while (str[++i] != '\0' && ft_isdigit(str[i]))
		res = res * 10 + str[i] - '0';
	if (neg == 1)
		res *= -1;
	return (res);
}
