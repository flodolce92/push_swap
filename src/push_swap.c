/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:11 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/15 18:17:18 by flo-dolc         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_ps	ps;

	ps.stack_a = NULL;
	ps.stack_b = NULL;
	check_args(argc, argv, &ps);
	fill_stack(&ps.stack_a, ps.args);
	print_stacks(ps.stack_a, ps.stack_b);
	if (argc == 2)
		free_matrix(ps.args);
	return (0);
}
