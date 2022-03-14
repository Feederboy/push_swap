/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 13:15:51 by maquentr          #+#    #+#             */
/*   Updated: 2021/01/22 12:41:15 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;
	size_t j;
	size_t stop;

	stop = 0;
	i = 0;
	if (!str || !to_find)
		return (NULL);
	if (to_find[0] == '\0')
		return (char *)(str);
	while (str[i] && i < n)
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (to_find[j] == str[i + j] && i + j < n)
			{
				if (to_find[j + 1] == '\0')
					return (char *)(str + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
