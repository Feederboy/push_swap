/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:30:21 by matt              #+#    #+#             */
/*   Updated: 2022/03/14 13:01:50 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *s)
{
	int	n;
	int	p;

	if (s && s->next)
	{
		n = s->n;
		p = s->pos;
		s->n = s->next->n;
		s->pos = s->next->pos;
		s->next->n = n;
		s->next->pos = p;
		return (1);
	}
	return (0);
}

int	sa(t_stack *s)
{
	if (!swap(s))
		return (0);
	write(1, "sa\n", 3);
	return (1);
}

t_stack	*rotate(t_stack *s)
{
	t_stack	*tmp;
	t_stack	*first;

	first = s;
	if (!first)
		return (NULL);
	s = s->next;
	tmp = s;
	if (!tmp)
		return (first);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	return (s);
}

t_stack	*ra(t_stack *s)
{
	s = rotate(s);
	if (!s)
		return (s);
	write(1, "ra\n", 3);
	return (s);
}
