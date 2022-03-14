/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:05:27 by maquentr          #+#    #+#             */
/*   Updated: 2021/01/22 12:34:55 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		nbrtobase(unsigned int nbr, char **str, int pos, char *base_to)
{
	if (nbr >= 10)
	{
		nbrtobase(nbr / 10, str, pos - 1, "0123456789");
		(*str)[pos] = base_to[nbr % 10];
	}
	else
		(*str)[pos] = base_to[nbr % 10];
}

char			*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*res;

	i = n;
	size = 1;
	if (n < 0)
		size++;
	while (i / 10)
	{
		size++;
		i /= 10;
	}
	res = malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	res[size] = '\0';
	nbrtobase((unsigned int)n, &res, size - 1, "0123456789");
	return (res);
}
