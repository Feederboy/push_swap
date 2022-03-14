/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:53:50 by matt              #+#    #+#             */
/*   Updated: 2022/03/03 14:54:17 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s;
		s = s->next;
		free(tmp);
	}
}

void	free_tab(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i++]);
	}
	free(arg);
}

void	free_all(t_stacklist *list, char **arg)
{
	if (list->tab)
		free(list->tab);
	free_list(list->stack_a);
	free_list(list->stack_b);
	free_tab(arg);
}
