/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 13:59:06 by maquentr          #+#    #+#             */
/*   Updated: 2021/01/22 12:30:59 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f' ||
			c == ' ');
}

int				ft_atoi(const char *str)
{
	int i;
	int sign;
	int r;
	int count;

	i = 0;
	sign = 1;
	r = 0;
	count = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (count >= 1)
			return (0);
		if (str[i++] == '-')
			sign = -1;
		count++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r * sign);
}
