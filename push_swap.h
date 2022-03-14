/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matt <maquentr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:59:28 by matt              #+#    #+#             */
/*   Updated: 2022/03/14 13:26:20 by maquentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				n;
	int				pos;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacklist
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			nb_instr;
	int			*tab;
}	t_stacklist;

/* main.c */
int		main(int ac, char **av);
int		checkers(char **av, char **arg, char ***args, int *nb_elems);

/* parsing.c */
char	*get_args(char **av);
void	aff_args(char **args);
int		check_args_digit(char **tab);
int		ft_strlen_double_tab(char **tab);
int		check_args_doubles(char **tab);
int		get_nb_elems(char **tab);

/* set_stack.c */
int		get_size_stack(t_stack *stack);
t_stack	*fill_stack_with_args(char **args);
void	print_stack(t_stack *stack);
int		init_stacks(t_stacklist *list, char **args);
int		*get_tab_from_list(t_stack *stack);

/* frees.c */
void	free_list(t_stack *s);
void	free_tab(char **arg);
void	free_all(t_stacklist *list, char **arg);

/* setters_order.c */
void	set_stack_pos_order_from_tab(t_stack *stack, int *tab);
int		*set_tab_order_from_stack(t_stack *stack);
void	set_tab_to_stack_pos(int *tab, t_stack *stack);
void	print_pos(t_stack *stack);
void	print_tab(int *tab);
void	set_order_tab(int *tab, int size);
void	set_order_tab2(int *tab, int size);

/* checkers_order.c */
int		sort_by_nb_elems(t_stacklist *list, int nb_elems);
int		check_tab_already_sorted(int *tab, int nb_elems);
int		check_below_sorted(int *tab, int i, int tmp);
int		check_above_sorted(int *tab, int i, int tmp, int nb_elems);

/* simple_sortings.c */
int		is_highest_elem(t_stack *stack, int n);
int		is_lowest_elem(t_stack *stack, int n);
int		two_elems_sort(t_stacklist *list, int nb_elems);
int		three_elems_sort(t_stacklist *list, int nb_elems);
int		five_elems_sort(t_stacklist *list, int nb_elems);

/* operations1.c */
int		sa(t_stack *s);
int		swap(t_stack *s);
t_stack	*ra(t_stack *s);
t_stack	*rotate(t_stack *s);

/* operations2.c */
t_stack	*rra(t_stack *s);
t_stack	*reverse_rotate(t_stack *s);
int		pb(t_stack **a, t_stack **b);
int		pa(t_stack **b, t_stack **a);
int		push(t_stack **src, t_stack **dst);

/* rad_sort.c */
int		get_ith_bit(t_stack *stack, int i);
int		get_highest_bit(t_stack *stack);
int		rad_sort(t_stacklist *list, int nb_elems);
int		radix_sort(t_stacklist *list, int nb_elems);

/* box_sort.c */
void	pb_or_ra(t_stacklist *list, int ith);
int		box_sorting(t_stacklist *list, int nb_elems, int hightest_bit, int ith);

#endif
