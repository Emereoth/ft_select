/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:18:31 by acottier          #+#    #+#             */
/*   Updated: 2016/09/19 12:18:42 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_newtab(int size)
{
	char		**res;
	int			i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
		i++;
	res[i] = NULL;
	return (res);
}
