/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:29:20 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/28 18:48:59 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_three(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	if (first->data > second->data)
	{
		if (second->data > third->data)
		{
			sa(stack);
			rra(stack);
		}
		else if (first->data > third->data)
			ra(stack);
		else
			sa(stack);
	}
	else if (first->data > third->data)
		rra(stack);
	else
	{
		sa(stack);
		ra(stack);
	}
}

// int	find_index_min(t_stack *stack)
// {
// 	t_stack	*current;
// 	int		min;

// 	current = stack;
// 	min = current->data;
// 	while (current)
// 	{
// 		if (current->data < min)
// 			min = current->data;
// 		current = current->next;
// 	}
// 	return (min);
// }

int	find_index_min(t_stack *stack)
{
	t_stack	*current;
	int		min;
	int		index_min;
	int		index;

	current = stack;
	min = current->data;
	index_min = 0;
	index = 0;
	while (current)
	{
		if (current->data < min)
		{
			min = current->data;
			index_min = index;
		}
		current = current->next;
		index++;
	}
	return (index_min);
}

void	sort_ten(t_stack **stack_a, t_stack **stack_b)
{
	int		index_min;
	int		size;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		index_min = find_index_min(*stack_a);
		if (index_min <= size / 2)
			while (index_min--)
				ra(stack_a);
		else
			while (size - index_min++)
				rra(stack_a);
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
