/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:25 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/06 15:59:06 by flo-dolc         ###   ########.fr       */
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
	int					data;
	struct s_stack	*next;
}	t_stack;

void	free_matrix(char **matrix);
void	print_error(char *msg, int exit_code);
char	**check_args(int argc, char **argv);
int		stack_size(t_stack *stack);
void	fill_stack(t_stack **stack_a, char **nums, char **argv);

void	add_node_front(t_stack **stack, int data);
void	add_node_back(t_stack **stack, int data);
void	print_stack(t_stack *stack);

void	swap(t_stack **stack);

#endif
