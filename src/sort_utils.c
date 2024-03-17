/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:29:20 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/17 14:53:49 by flo-dolc         ###   ########.fr       */
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
