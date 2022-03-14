/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:21:04 by matt              #+#    #+#             */
/*   Updated: 2022/03/14 13:16:57 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*reverse_rotate(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	if (!tmp || !tmp->next)
		return (NULL);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = s;
	s = tmp->next;
	tmp->next = NULL;
	return (s);
}

t_stack	*rra(t_stack *s)
{
	s = reverse_rotate(s);
	if (!s)
		return (s);
	write(1, "rra\n", 4);
	return (s);
}

int	push(t_stack **src, t_stack **dst)
{
	t_stack	*aux;
	t_stack	*tmp;

	if (!(*src))
		return (0);
	aux = malloc(sizeof(t_stack));
	if (!aux)
		return (0);
	aux->n = (*src)->n;
	aux->pos = (*src)->pos;
	aux->next = *dst;
	*dst = aux;
	tmp = *src;
	*src = (*src)->next;
	free(tmp);
	return (1);
}

int	pb(t_stack **a, t_stack **b)
{
	if (!push(a, b))
		return (0);
	write(1, "pb\n", 3);
	return (1);
}

int	pa(t_stack **b, t_stack **a)
{
	if (!push(b, a))
		return (0);
	write(1, "pa\n", 3);
	return (1);
}
