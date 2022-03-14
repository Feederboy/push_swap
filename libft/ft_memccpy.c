/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:28:20 by maquentr          #+#    #+#             */
/*   Updated: 2021/01/18 19:45:55 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ddst;
	unsigned char	*ssrc;

	i = 0;
	ssrc = (unsigned char *)src;
	ddst = (unsigned char *)dest;
	if (!dest)
		return (NULL);
	while (i < n)
	{
		ddst[i] = ssrc[i];
		if (ssrc[i] == ((unsigned char)c))
			return ((void*)&ddst[i + 1]);
		i++;
	}
	return (NULL);
}
