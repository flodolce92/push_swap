/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 05:22:48 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/15 18:21:27 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = stack;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	fill_stack(t_stack **stack_a, char **nums)
{
	int	i;

	i = 0;
	if (nums != NULL)
	{
		while (nums[i])
		{
			add_node_back(stack_a, ft_atoi(nums[i]));
			i++;
		}
	}
}

void	print_stack(t_stack *stack)
{
	if (stack == NULL)
	{
		ft_printf("Empty stack\n");
		return ;
	}
	while (stack)
	{
		ft_printf("%d ", stack->data);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Stack A: ");
	print_stack(stack_a);
	ft_printf("Stack B: ");
	print_stack(stack_b);
}
