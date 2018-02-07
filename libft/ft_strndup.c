/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:37:16 by acottier          #+#    #+#             */
/*   Updated: 2016/01/31 18:14:57 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*res;

	if (!(res = ft_strnew(ft_strlen((char*)s1))))
		return (0);
	ft_strncpy(res, (char*)s1, n);
	return (res);
}
