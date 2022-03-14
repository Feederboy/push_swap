/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:29:27 by matt              #+#    #+#             */
/*   Updated: 2022/03/14 13:02:32 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->pos);
}

void	pb_or_ra(t_stacklist *list, int ith)
{
	if (get_ith_bit(list->stack_a, ith))
		list->stack_a = ra(list->stack_a);
	else
		pb(&list->stack_a, &list->stack_b);
}

int	box_sorting(t_stacklist *list, int nb_elems, int highest_bit, int ith)
{
	int	n;

	n = 0;
	while (list->stack_a && (n < nb_elems))
	{
		pb_or_ra(list, ith);
		list->nb_instr = list->nb_instr + 1;
		n++;
	}
	while (list->stack_b)
	{
		list->nb_instr = list->nb_instr + 1;
		pa(&list->stack_b, &list->stack_a);
	}
	if (ith < highest_bit)
		box_sorting(list, nb_elems, highest_bit, ith + 1);
	return (1);
}
