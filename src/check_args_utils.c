/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:41:56 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/28 16:42:06 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int_overflow(char *arg)
{
	long long	num;

	num = ft_atoll(arg);
	if (num > INT_MAX || num < INT_MIN)
	{
		errno = ERANGE;
		print_error("Integer overflow", 1);
	}
	return (num);
}

int	check_duplicates(t_stack *stack, int num)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		if (current->data == num)
			return (1);
		current = current->next;
	}
	return (0);
}
