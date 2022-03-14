/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:21:01 by maquentr          #+#    #+#             */
/*   Updated: 2021/01/23 14:43:49 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void *ptr;

	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nitems * size);
	return (ptr);
}
