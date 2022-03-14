/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:54:35 by maquentr          #+#    #+#             */
/*   Updated: 2021/01/18 19:35:20 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (s1 > s2)
		while (i < n)
		{
			ss1[n - 1] = ss2[n - 1];
			n--;
		}
	else
		while (i < n)
		{
			ss1[i] = ss2[i];
			i++;
		}
	return ((void*)ss1);
}
