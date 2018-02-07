/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:22:46 by acottier          #+#    #+#             */
/*   Updated: 2015/12/10 21:30:06 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dsttmp;
	char	*srctmp;
	int		i;

	dsttmp = (char*)dst;
	srctmp = (char*)src;
	if (srctmp < dsttmp)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			dsttmp[i] = srctmp[i];
			i--;
		}
	}
	else if (srctmp != dsttmp)
	{
		i = -1;
		while (++i < (int)len)
			dsttmp[i] = srctmp[i];
	}
	return (dst);
}
