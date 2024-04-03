/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:38:15 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/04/03 02:10:20 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *stack, int pivot)
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
	int		pivot;
	int		index;
	int		i;
	int		j;

	i = 1;
	while (i <= 4)
	{
		j = 0;
		pivot = sorted_array[(size / 4 * i) - 1];
		while (j < size / 4)
		{
			index = get_index(*stack_a, pivot);
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
}

void	sort_more(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		*sorted_array;

	(void)stack_b;
	sorted_array = to_array(*stack_a, size);
	if (size <= 100)
		sort_hundred(stack_a, stack_b, sorted_array, size);
	// else
	// 	sort_five_hundred(stack_a, stack_b, sorted_array);
	free(sorted_array);
}
