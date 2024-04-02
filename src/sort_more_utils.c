/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:38:15 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/04/02 20:49:30 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_hundred(t_stack **stack_a, t_stack **stack_b, int *sorted_array, int size)
{
	int		i;
	int		j;
	int		pivot;
	int		index;
	t_stack	*current;

	pivot = sorted_array[size / 4];
	index = 0;
	j = 0;
	current = *stack_a;
	while (j < size / 4)
	{
		while (/* condition */)
		{
			if ((*stack_a)->data <= pivot)
			{
				if (index <= size / 2)
				{
					i = -1;
					while (++i < index)
						ra(stack_a);
				}
				else
				{
					i = size - index;
					while (i--)
						rra(stack_a);
				}
				pb(stack_a, stack_b);
			}
		}
		j++;
		index++;
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
