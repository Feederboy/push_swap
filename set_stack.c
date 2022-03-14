/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:25:07 by matt              #+#    #+#             */
/*   Updated: 2022/03/14 13:22:45 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*fill_stack_with_args(char **args)
{
	t_stack	*root;
	t_stack	*next;
	t_stack	*tmp;
	int		i;

	i = 1;
	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->n = ft_atoi(args[0]);
	next = tmp;
	root = tmp;
	while (args[i])
	{
		tmp = malloc(sizeof(t_stack));
		if (!tmp)
			return (NULL);
		tmp->n = ft_atoi(args[i++]);
		tmp->next = NULL;
		next->next = tmp;
		next = next->next;
	}
	return (root);
}

int	*get_tab_from_list(t_stack *stack)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * (get_size_stack(stack) + 1));
	if (!tab)
		return (NULL);
	while (stack)
	{
		tab[i++] = stack->n;
		stack = stack->next;
	}
	tab[i] = 0;
	return (tab);
}

int	init_stacks(t_stacklist *list, char **args)
{
	list->nb_instr = 0;
	list->stack_b = NULL;
	list->stack_a = fill_stack_with_args(args);
	if (!list->stack_a)
		return (-1);
	list->tab = get_tab_from_list(list->stack_a);
	if (!list->tab)
		return (-1);
	set_stack_pos_order_from_tab(list->stack_a, list->tab);
	free(list->tab);
	list->tab = set_tab_order_from_stack(list->stack_a);
	if (!list->tab)
		return (-1);
	set_order_tab2(list->tab, get_size_stack(list->stack_a));
	set_tab_to_stack_pos(list->tab, list->stack_a);
	return (1);
}
