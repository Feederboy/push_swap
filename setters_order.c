/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:00:49 by matt              #+#    #+#             */
/*   Updated: 2022/03/14 13:23:10 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack_pos_order_from_tab(t_stack *stack, int *tab)
{
	int	size;
	int	i;

	size = get_size_stack(stack);
	while (stack)
	{
		stack->pos = 1;
		i = 0;
		while (i < size)
		{
			if (stack->n > tab[i])
				stack->pos++;
			i++;
		}
		stack = stack->next;
	}
}

int	*set_tab_order_from_stack(t_stack *stack)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * (get_size_stack(stack) + 1));
	if (!tab)
		return (NULL);
	while (stack)
	{
		tab[i++] = stack->pos;
		stack = stack->next;
	}
	tab[i] = 0;
	return (tab);
}

void	set_tab_to_stack_pos(int *tab, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = tab[i++];
		stack = stack->next;
	}
}

void	set_order_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j != i && tab[j] == tab[i])
			{
				tab[j] += 1;
				set_order_tab(tab, size);
			}
			j++;
		}
		i++;
	}
}

void	set_order_tab2(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j != i && tab[j] == tab[i])
			{
				tab[j] += 1;
				continue ;
			}
			j++;
		}
		i++;
	}
}
