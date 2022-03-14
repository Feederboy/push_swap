/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:01:46 by matt              #+#    #+#             */
/*   Updated: 2022/03/14 13:18:05 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_args(char **av)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 1;
	res = "";
	while (av[i])
	{
		if (i > 1)
			tmp = res;
		res = ft_strjoin(res, av[i++]);
		if (!res)
			return (NULL);
		if (i > 2)
			free(tmp);
		if (!av[i])
			break ;
		tmp = res;
		res = ft_strjoin(tmp, " ");
		free(tmp);
		if (!res)
			return (NULL);
	}
	return (res);
}

int	check_args_digit(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] < 48 || tab[i][j] > 57) && tab[i][j] != 45)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strlen_double_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	check_args_doubles(char **tab)
{
	int		i;
	int		j;
	long	tmp;

	i = 0;
	while (tab[i])
	{
		tmp = atol(tab[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (1);
		j = ft_strlen_double_tab(tab) - 1;
		while (tab[j] && j > i)
		{
			if (tmp == ft_atoi(tab[j]))
				return (1);
			j--;
		}
		i++;
	}
	return (0);
}

int	get_nb_elems(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
