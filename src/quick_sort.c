/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:23:17 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/04/08 22:32:40 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	divide(int *array, int start, int end)
{
	int	i;
	int	j;
	int	pivot;
	int	tmp;

	i = start - 1;
	j = start;
	pivot = array[end];
	while (j <= end)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
		}
		j++;
	}
	i++;
	tmp = array[end];
	array[end] = array[i];
	array[i] = tmp;
	return (i);
}

static void	quick_sort(int *array, int start, int end)
{
	int	div;

	if (start < end)
	{
		div = divide(array, start, end);
		quick_sort(array, start, div - 1);
		quick_sort(array, div + 1, end);
	}
}

int	*to_array(t_stack *stack, int size)
{
	int		*array;
	int		i;
	t_stack	*current;

	array = malloc(sizeof(int) * size);
	if (!array)
		print_error("Array allocation failed.", 1);
	current = stack;
	i = 0;
	while (current)
	{
		array[i] = current->data;
		current = current->next;
		i++;
	}
	quick_sort(array, 0, size - 1);
	return (array);
}
