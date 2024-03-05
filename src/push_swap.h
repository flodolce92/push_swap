/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:25 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/06 15:47:10 by flo-dolc         ###   ########.fr       */
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

typedef struct s_stack_node
{
	int					data;
	struct s_stack_node	*next;
}	t_stack_node;

void	free_matrix(char **matrix);
void	print_error(char *msg, int exit_code);
char	**check_args(int argc, char **argv);
int		stack_size(t_stack_node *stack);
void	fill_stack(t_stack_node **stack_a, char **nums, char **argv);

void	add_node_front(t_stack_node **stack, int data);
void	add_node_back(t_stack_node **stack, int data);
void	print_stack(t_stack_node *stack);

void	swap(t_stack_node **stack);

#endif
