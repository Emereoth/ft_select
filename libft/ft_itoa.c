/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:53:19 by acottier          #+#    #+#             */
/*   Updated: 2015/12/18 05:15:20 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill(int n, int o, int i, char *result)
{
	int k;

	k = n;
	result[i] = '\0';
	if (o == 1)
		result[0] = '-';
	while ((i-- > 0 && o == 0) || (i > 0 && o == 1))
	{
		result[i] = (k % 10) + 48;
		k = (k - (k % 10)) / 10;
	}
	return (result);
}

static int	ft_len(int i, int n)
{
	int k;

	k = n;
	while (k != 0)
	{
		k = (k - (k % 10)) / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		o;

	o = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		o = 1;
		n = -n;
		i++;
	}
	if (n == 0)
	{
		if (!(result = ft_strnew(2)))
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	if (!(result = ft_strnew(ft_len(i, n) + 1)))
		return (NULL);
	return (ft_fill(n, o, ft_len(i, n), result));
}
