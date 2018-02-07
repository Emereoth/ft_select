/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:10:20 by acottier          #+#    #+#             */
/*   Updated: 2015/12/18 05:07:22 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zone;

	if (!(zone = (void*)(malloc(sizeof(*zone) * size))))
		return (0);
	ft_bzero(zone, size);
	return (zone);
}
