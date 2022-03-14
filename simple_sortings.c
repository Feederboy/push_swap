/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sortings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:55:21 by matt              #+#    #+#             */
/*   Updated: 2022/03/14 13:25:23 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_highest_elem(t_stack *stack, int n)
{
	while (stack)
	{
		if (n < stack->pos)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_lowest_elem(t_stack *stack, int n)
{
	while (stack)
	{
		if (n > stack->pos)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	two_elems_sort(t_stacklist *list, int nb_elems)
{
	if (!check_tab_already_sorted(list->tab, nb_elems))
		sa(list->stack_a);
	return (1);
}

int	three_elems_sort(t_stacklist *list, int nb_elems)
{
	int	*aux;

	aux = list->tab;
	while (!check_tab_already_sorted(aux, nb_elems))
	{
		if (list->stack_a->pos == list->stack_a->next->pos + 1)
			sa(list->stack_a);
		else if (is_highest_elem(list->stack_a, list->stack_a->pos))
			list->stack_a = ra(list->stack_a);
		else if (is_highest_elem(list->stack_a, list->stack_a->next->pos))
			list->stack_a = rra(list->stack_a);
		free(aux);
		aux = NULL;
		aux = set_tab_order_from_stack(list->stack_a);
	}
	free(aux);
	list->tab = NULL;
	return (1);
}

int	five_elems_sort(t_stacklist *list, int nb_elems)
{
	while (get_size_stack(list->stack_a) != 3)
	{
		if (is_highest_elem(list->stack_a, list->stack_a->pos))
			pb(&list->stack_a, &list->stack_b);
		else if (is_lowest_elem(list->stack_a, list->stack_a->pos))
			pb(&list->stack_a, &list->stack_b);
		else
			list->stack_a = ra(list->stack_a);
	}
	free(list->tab);
	list->tab = set_tab_order_from_stack(list->stack_a);
	three_elems_sort(list, get_size_stack(list->stack_a));
	while (get_size_stack(list->stack_a) != nb_elems)
	{
		pa(&list->stack_b, &list->stack_a);
		if (is_highest_elem(list->stack_a, list->stack_a->pos))
			list->stack_a = ra(list->stack_a);
	}
	return (1);
}
