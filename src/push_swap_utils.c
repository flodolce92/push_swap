/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 05:22:48 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/05 09:07:55 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack_node *stack)
{
	int				size;
	t_stack_node	*current;

	size = 0;
	current = stack;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	fill_stack(t_stack_node **stack_a, char **nums, char **argv)
{
	int	i;

	i = 0;
	if (nums != NULL)
	{
		while (nums[i])
		{
			add_node(stack_a, ft_atoi(nums[i]));
			i++;
		}
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			add_node(stack_a, ft_atoi(argv[i]));
			i++;
		}
	}
}

void	print_stack(t_stack_node *stack)
{
	ft_putstr_fd("----Printing Stack (Top to Down)-------\n", 1);
	while (stack)
	{
		ft_putstr_fd("Data: ", 1);
		ft_putnbr_fd(stack->data, 1);
		ft_putstr_fd("\n", 1);
		stack = stack->next;
	}
}
