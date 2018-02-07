/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:16:12 by acottier          #+#    #+#             */
/*   Updated: 2016/09/19 12:16:43 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_freetab(char **my_tab)
{
	int		i;

	i = 0;
	if (my_tab == NULL)
		return ;
	while (my_tab[i] != NULL)
		free(my_tab[i++]);
	free(my_tab);
}
