/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:12:23 by maquentr          #+#    #+#             */
/*   Updated: 2021/01/15 15:11:27 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *curr;

	curr = *alst;
	if (alst)
	{
		if (*alst)
		{
			curr = ft_lstlast(*alst);
			curr->next = new;
		}
		else
			*alst = new;
	}
}
