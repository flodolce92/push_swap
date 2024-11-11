/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:38:15 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/04/11 20:37:20 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

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

void	count_moves_a(t_stack **stack_a, t_stack **b_node)
{
	t_stack	*current;
	int		diff;
	int		min_diff;

	current = *stack_a;
	min_diff = INT_MAX;
	while (current)
	{
		if ((*b_node)->index < current->index)
		{
			diff = current->index - (*b_node)->index;
			if (diff < min_diff)
			{
				min_diff = diff;
			}
		}
		current = current->next;
	}
}

void	count_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		rb;
	int		size;

	rb = 0;
	current = *stack_b;
	size = stack_size(*stack_b);
	while (current)
	{
		if (rb <= size / 2)
			current->rb = rb;
		else
			current->rb = -(size - rb);
		rb++;
		count_moves_a(stack_a, &current);
		current->moves = abs(current->ra) + abs(current->rb);
		current = current->next;
	}
}

static void	back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	index_max;
	int	size;

	count_moves(stack_a, stack_b);
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

static int	i_under_pivot(t_stack *stack, int pivot)
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

void	begin_sort(t_stack **stack_a, t_stack **stack_b, int *array, int size)
{
	int	index;
	int	i;
	int	j;
	int	n_blocks;

	i = 0;
	n_blocks = 5;
	if (size > 100)
		n_blocks = 10;
	while (++i <= (n_blocks - 1))
	{
		j = -1;
		while (++j < size / n_blocks)
		{
			index = i_under_pivot(*stack_a, array[(size / n_blocks * i) - 1]);
			if (index <= size / 2)
				while (index--)
					ra(stack_a);
			else
				while (size - index++)
					rra(stack_a);
			pb(stack_a, stack_b);
		}
	}
}

void	indexing(int *sorted_array, t_stack **stack_a, int size)
{
	t_stack	*current;
	int		i;

	current = *stack_a;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->data == sorted_array[i])
			{
				current->index = i;
				break;
			}
			i++;
		}
		current = current->next;
	}
}

void	sort_more(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	*sorted_array;

	sorted_array = to_array(*stack_a, size);
	indexing(sorted_array, stack_a, size);
	begin_sort(stack_a, stack_b, sorted_array, size);
	sort_few(stack_a, stack_b, stack_size(*stack_a));
	back_to_a(stack_a, stack_b);
	free(sorted_array);
}
