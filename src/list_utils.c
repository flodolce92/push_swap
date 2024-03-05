/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 05:49:09 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/06 15:46:53 by flo-dolc         ###   ########.fr       */
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
	new->next = NULL;
	return (new);
}

void	add_node_front(t_stack_node **stack, int number)
{
	t_stack_node	*new;

	new = new_node(number);
	if (!stack)
		return ;
	if (*stack != NULL)
		new->next = *stack;
	*stack = new;
}

void	add_node_back(t_stack_node **stack, int number)
{
	t_stack_node	*p;

	if (!stack)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node(number);
		return ;
	}
	p = *stack;
	while (p->next)
		p = p->next;
	p->next = new_node(number);
}
