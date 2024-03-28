/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:25 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/28 18:48:59 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ps
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		argc;
	char	**args;
}	t_ps;

void	init_struct(t_ps *ps, int argc);
void	free_matrix(char **matrix);
void	free_stack(t_stack *stack);
void	free_all(t_ps *ps);
void	print_error(char *msg, int exit_code);
void	check_args(int argc, char **argv, t_ps *ps);
int		check_int_overflow(char *arg);
int		check_duplicates(t_stack *stack, int num);
int		stack_size(t_stack *stack);
void	fill_stack(t_stack **stack_a, char **nums, t_ps *ps);

t_stack	*new_node(int data);
t_stack	*last_node(t_stack *stack);
void	add_node_front(t_stack **stack, int data);
void	add_node_back(t_stack **stack, int data);
void	print_stack(t_stack *stack);
void	print_stacks(t_stack *a, t_stack *b);

void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	push(t_stack **from, t_stack **to);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

int		is_ordered(t_stack *stack);
void	sort_three(t_stack **stack);
void	sort_ten(t_stack **a, t_stack **b);

#endif
