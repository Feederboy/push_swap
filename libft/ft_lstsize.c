/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maquentr <maquentr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:05:19 by maquentr          #+#    #+#             */
/*   Updated: 2021/01/18 19:32:57 by matt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*curr;

	curr = lst;
	len = 0;
	while (curr != NULL)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}
