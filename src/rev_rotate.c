/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:49:32 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/12 17:04:01 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;
	t_stack	*prev_last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	head = *stack;
	last = last_node(*stack);
	prev_last = *stack;
	while (prev_last->next != last)
		prev_last = prev_last->next;
	prev_last->next = NULL;
	last->next = head;
	*stack = last;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}

