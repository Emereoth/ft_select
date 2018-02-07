/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:19:07 by acottier          #+#    #+#             */
/*   Updated: 2015/12/21 18:20:06 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse(char *str)
{
	int		i;
	int		len;
	char	*res;

	len = ft_strlen(str);
	res = ft_strnew(len);
	i = 0;
	while (len > 0)
	{
		res[i] = str[len - 1];
		len--;
		i++;
	}
	res[i] = '\0';
	return (res);
}
