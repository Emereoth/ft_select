/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:55:38 by acottier          #+#    #+#             */
/*   Updated: 2016/02/13 09:49:30 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupchr(const char *s1, char c)
{
	char	*res;
	int		i;
	int		j;

	i = (int)ft_strlenchr((char*)s1, c);
	j = 0;
	if (!(res = ft_strnew(i + 1)))
		return (0);
	while (s1[j] != '\0' && s1[j] != c)
	{
		res[j] = s1[j];
		j++;
	}
	res[i] = '\0';
	return (res);
}
