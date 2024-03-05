/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:11 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/05 09:06:19 by flo-dolc         ###   ########.fr       */
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
	t_stack_node	*stack_a;
	// t_stack_node	*stack_b;
	char			**nums;

	stack_a = NULL;
	// stack_b = NULL;
	nums = check_args(argc, argv);
	fill_stack(&stack_a, nums, argv);
	print_stack(stack_a);
	free_matrix(nums);
	return (0);
}
