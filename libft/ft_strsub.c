/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:45:12 by acottier          #+#    #+#             */
/*   Updated: 2015/12/18 05:12:55 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < (int)len)
	{
		res[i] = (char)s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
