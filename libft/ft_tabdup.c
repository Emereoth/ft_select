/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 18:44:25 by acottier          #+#    #+#             */
/*   Updated: 2016/09/06 18:51:53 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **my_tab)
{
	char	**res;
	int		i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (ft_tabsize(my_tab) + 1));
	while (my_tab[i])
	{
		res[i] = ft_strdup(my_tab[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
