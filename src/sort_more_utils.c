/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:38:15 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/04/02 19:27:14 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		*sorted_array;

	(void)stack_b;
	sorted_array = to_array(*stack_a, size);
	// if (size <= 100)
	// 	sort_hundred(stack_a, stack_b, sorted_array);
	// else
	// 	sort_five_hundred(stack_a, stack_b, sorted_array);
	free(sorted_array);
}

// void	sort_hundred(t_stack **stack_a, t_stack **stack_b, int *sorted_array)
// {
// }
