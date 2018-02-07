/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:34:39 by acottier          #+#    #+#             */
/*   Updated: 2015/12/02 13:21:37 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	char				*str;
	char				*str2;

	str = (char*)src;
	str2 = (char*)dst;
	i = 0;
	while ((i < n) && (str[i] != '\0'))
	{
		str2[i] = str[i];
		i++;
	}
	return (dst);
}
