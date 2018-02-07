/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:25:19 by acottier          #+#    #+#             */
/*   Updated: 2015/12/18 05:14:36 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int		i;
	int		res;
	int		word_bool;

	res = 0;
	i = 0;
	word_bool = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			word_bool = 0;
		else
		{
			if (word_bool == 0)
				res++;
			word_bool = 1;
		}
		i++;
	}
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	*start;
	char	**res;

	words = ft_word_count((char *)s, c);
	if (!c || !s)
		return (NULL);
	if (!(res = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	start = (char *)s;
	while (*s)
	{
		if (*s == c)
		{
			if (start != s)
				*(res++) = ft_strsub(start, 0, s - start);
			start = (char *)s + 1;
		}
		++s;
	}
	if (start != s)
		*(res++) = ft_strsub(start, 0, s - start);
	*res = NULL;
	return (res - words);
}
