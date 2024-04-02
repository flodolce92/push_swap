/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:11 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/04/02 19:48:04 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *msg, int exit_code)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	if (errno != 0)
		perror("");
	exit(exit_code);
}

void	init_struct(t_ps *ps, int argc)
{
	ps->stack_a = NULL;
	ps->stack_b = NULL;
	ps->argc = argc;
	ps->args = NULL;
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		size;

	init_struct(&ps, argc);
	check_args(argc, argv, &ps);
	fill_stack(&ps.stack_a, ps.args, &ps);
	if(is_ordered(ps.stack_a))
	{
		ft_printf("Stack is already ordered\n");
		print_stacks(ps.stack_a, ps.stack_b);
		free_all(&ps);
		return (0);
	}
	size = stack_size(ps.stack_a);
	if (size == 2)
		sa(&ps.stack_a);
	else if (size == 3)
		sort_three(&ps.stack_a);
	else if (size <= 10)
		sort_ten(&ps.stack_a, &ps.stack_b, size);
	else
		sort_more(&ps.stack_a, &ps.stack_b, size);
	print_stacks(ps.stack_a, ps.stack_b);
	free_all(&ps);
	return (0);
}
