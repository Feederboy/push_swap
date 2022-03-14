/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:08:53 by maquentr          #+#    #+#             */
/*   Updated: 2021/01/23 14:40:02 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p;
	unsigned char		*q;

	i = 0;
	if (!dst || !src)
		return (dst);
	p = (unsigned char *)src;
	q = (unsigned char *)dst;
	while (i < n)
	{
		q[i] = p[i];
		i++;
	}
	return (dst);
}
