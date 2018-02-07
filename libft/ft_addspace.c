/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 11:46:39 by acottier          #+#    #+#             */
/*   Updated: 2016/09/01 18:23:29 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addspace(char *str, int nbr)
{
	char	*res;
	char	*toadd;

	toadd = ft_strnew(nbr);
	ft_memset(toadd, ' ', nbr);
	if (!str)
		return (ft_strdup(toadd));
	res = ft_strjoin(str, toadd);
	free(str);
	free(toadd);
	return (res);
}
