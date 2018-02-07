/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trijoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 19:04:38 by acottier          #+#    #+#             */
/*   Updated: 2016/09/01 17:57:16 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		find_length(char *s1, char *s2, char *s3)
{
	int		res;

	res = ft_strlen(s1);
	res += ft_strlen(s2);
	res += ft_strlen(s3);
	return (res);
}

static	char	*ft_check(char *s1, char *s2, char *s3)
{
	if (s1 && s2 && s2[0] == '/' && !s2[1] && s1[ft_strlen(s1) - 1] == '/')
		return (ft_strjoin(s1, s3));
	if (!s1 && s2 && s3)
	{
		if (s2[0] == '/' && !s2[1])
			return (ft_strdup(s3));
		return (ft_strjoin(s2, s3));
	}
	if (s1 && s2 && s3)
		return (0);
	if (!s2 && s1 && s3)
		return (ft_strjoin(s1, s3));
	if (!s3 && s1 && s2)
		return (ft_strjoin(s2, s3));
	if (s1 && !s2 && !s3)
		return (ft_strdup(s1));
	if (!s1 && s2 && !s3)
		return (ft_strdup(s2));
	if (!s1 && !s2 && s3)
		return (ft_strdup(s3));
	return (NULL);
}

char			*ft_trijoin(char *s1, char *s2, char *s3)
{
	int		length;
	int		i;
	int		j;
	char	*res;

	if ((res = ft_check(s1, s2, s3)) != 0)
		return (res);
	i = 0;
	j = 0;
	length = find_length(s1, s2, s3);
	if (!(res = ft_strnew(length)))
		exit(1);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	j = 0;
	while (s3[j])
		res[i++] = s3[j++];
	return (res);
}
