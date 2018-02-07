/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 10:30:39 by acottier          #+#    #+#             */
/*   Updated: 2016/09/01 17:58:31 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradv(char *str, int i)
{
	char	*swap;

	swap = ft_strdup(str + i);
	free(str);
	str = ft_strdup(swap);
	free(swap);
	return (str);
}
