/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:21:03 by matt              #+#    #+#             */
/*   Updated: 2022/03/14 13:22:15 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_ith_bit(t_stack *stack, int i)
{
	return (((stack->pos) >> i) & 1);
}

int	get_highest_bit(t_stack *stack)
{
	int	i;
	int	highest;

	highest = 0;
	while (stack)
	{
		i = 0;
		while (i < 32)
		{
			if (get_ith_bit(stack, i) && i > highest)
				highest = i;
			i++;
		}
		stack = stack->next;
	}
	return (highest);
}

int	radix_sort(t_stacklist *list, int nb_elems)
{
	int	highest_bit;
	int	ith;

	ith = 0;
	highest_bit = get_highest_bit(list->stack_a);
	if (!highest_bit)
		return (1);
	box_sorting(list, nb_elems, highest_bit, ith);
	return (1);
}

int	rad_sort(t_stacklist *list, int nb_elems)
{
	if (check_tab_already_sorted(list->tab, nb_elems))
		return (1);
	else
		radix_sort(list, nb_elems);
	free(list->tab);
	list->tab = NULL;
	return (1);
}
