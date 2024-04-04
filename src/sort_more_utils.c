/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:38:15 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/04/05 16:40:09 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_max(t_stack *stack)
{
	t_stack	*current;
	int		max;
	int		index_max;
	int		index;

	current = stack;
	max = current->data;
	index_max = 0;
	index = 0;
	while (current)
	{
		if (current->data > max)
		{
			max = current->data;
			index_max = index;
		}
		current = current->next;
		index++;
	}
	return (index_max);
}

static void	back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	index_max;
	int	size;

	size = stack_size(*stack_b);
	while (size)
	{
		index_max = find_index_max(*stack_b);
		if (index_max <= size / 2)
			while (index_max--)
				rb(stack_b);
		else
			while (size - index_max++)
				rrb(stack_b);
		pa(stack_a, stack_b);
		size--;
	}
}

static int	get_index_under_pivot(t_stack *stack, int pivot)
{
	t_stack	*current;
	int		index;

	current = stack;
	index = 0;
	while (current)
	{
		if (current->data <= pivot)
			return (index);
		index++;
		current = current->next;
	}
	return (-1);
}

void	sort_hundred(t_stack **stack_a, t_stack **stack_b, int *sorted_array, int size)
{
	int	pivot;
	int	index;
	int	i;
	int	j;

	i = 1;
	while (i <= 4)
	{
		j = 0;
		pivot = sorted_array[(size / 5 * i) - 1];
		while (j < size / 5)
		{
			index = get_index_under_pivot(*stack_a, pivot);
			if (index <= size / 2)
				while (index--)
					ra(stack_a);
			else
				while (size - index++)
					rra(stack_a);
			pb(stack_a, stack_b);
			j++;
		}
		i++;
	}
	sort_ten(stack_a, stack_b, stack_size(*stack_a));
	back_to_a(stack_a, stack_b);
}

void	sort_more(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	*sorted_array;

	sorted_array = to_array(*stack_a, size);
	if (size <= 100)
		sort_hundred(stack_a, stack_b, sorted_array, size);
	// else
	// 	sort_five_hundred(stack_a, stack_b, sorted_array);
	free(sorted_array);
}
