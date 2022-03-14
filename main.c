/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:19:01 by matt              #+#    #+#             */
/*   Updated: 2022/03/14 13:15:47 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_rad_sort(t_stacklist *list, int nb_elems)
{
	if (sort_by_nb_elems(list, nb_elems))
		return (1);
	return (0);
}

int	checkers(char **av, char **arg, char ***args, int *nb_elems)
{
	*arg = get_args(av);
	if (!arg)
		return (write(2, "ERROR\n", 6));
	*args = ft_split(*arg, ' ');
	free(*arg);
	if (!(*args) || !(*args[0]))
	{
		free_tab(*args);
		return (1);
	}
	*nb_elems = get_nb_elems(*args);
	if (*nb_elems == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	char		*arg;
	char		**args;
	int			nb_elems;
	t_stacklist	list;

	if (ac < 2)
		return (1);
	else
	{
		if (checkers(av, &arg, &args, &nb_elems) != 0)
			return (1);
		if (check_args_doubles(args) || check_args_digit(args)
			|| init_stacks(&list, args) == -1)
		{
			free_tab(args);
			return (write(2, "ERROR\n", 6));
		}
		if (!not_rad_sort(&list, nb_elems))
			rad_sort(&list, nb_elems);
		free_all(&list, args);
	}
	return (0);
}
