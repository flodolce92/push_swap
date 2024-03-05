/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 05:49:09 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/05 06:19:46 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*new_node(int number)
{
	t_stack_node	*new;

	new = (t_stack_node *) malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->data = number;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_node(t_stack_node **stack, int number)
{
	t_stack_node	*new;

	new = new_node(number);
	if (!stack)
		return ;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}
