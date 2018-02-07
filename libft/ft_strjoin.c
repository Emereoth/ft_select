/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:53:12 by acottier          #+#    #+#             */
/*   Updated: 2016/03/19 15:07:45 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	int		s1_length;
	char	*res;
	int		i;

	i = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	length = ft_strlen(s1) + ft_strlen(s2);
	s1_length = (int)ft_strlen(s1);
	if (!(res = ft_strnew(length)))
		return (0);
	while (i < length)
	{
		if (i < s1_length)
			res[i] = (char)s1[i];
		else
			res[i] = (char)s2[i - s1_length];
		i++;
	}
	res[length] = '\0';
	return (res);
}
