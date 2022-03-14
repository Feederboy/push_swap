/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:39:14 by matt              #+#    #+#             */
/*   Updated: 2022/03/14 13:26:18 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_below_sorted(int *tab, int i, int tmp)
{
	while (i > 0)
	{
		if (tab[i] > tmp)
			return (0);
		i--;
	}
	return (1);
}

int	check_above_sorted(int *tab, int i, int tmp, int nb_elems)
{
	while (i < nb_elems)
	{
		if (tab[i] < tmp)
			return (0);
		i++;
	}
	return (1);
}

int	check_tab_already_sorted(int *tab, int nb_elems)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < nb_elems)
	{
		tmp = tab[i];
		if (!check_below_sorted(tab, i, tmp))
			return (0);
		if (!check_above_sorted(tab, i, tmp, nb_elems))
			return (0);
		i++;
	}
	return (1);
}

int	sort_by_nb_elems(t_stacklist *list, int nb_elems)
{
	if (check_tab_already_sorted(list->tab, nb_elems))
		return (1);
	if (nb_elems == 1)
		return (1);
	if (nb_elems == 2)
		return (two_elems_sort(list, nb_elems));
	if (nb_elems == 3)
		return (three_elems_sort(list, nb_elems));
	if (nb_elems < 6)
		return (five_elems_sort(list, nb_elems));
	return (0);
}
