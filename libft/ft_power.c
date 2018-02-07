/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:14:18 by acottier          #+#    #+#             */
/*   Updated: 2015/12/18 05:18:42 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int base, int power)
{
	if (power == 0)
		return (1);
	else if (power == 1)
		return (base);
	else if (power > 1)
		return (base * ft_power(base, power - 1));
	else
		return (0);
}
