/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:54:38 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/22 02:09:14 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	check_int_overflow(char *arg)
// {
// 	long long int	num;

// 	num = ft_atoll(arg);
// 	if (num > INT_MAX || num < INT_MIN)
// 		print_error("Integer overflow", 1);
// }

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

static int	is_valid_num(char *num)
{
	int	i;

	i = 0;
	if (ft_strlen(num) == 0)
		print_error("Empty argument", 1);
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i] != '\0')
	{
		if (ft_isdigit(num[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static char	**check_single_arg(char *arg)
{
	int		i;
	char	**nums;

	i = 0;
	if (ft_strlen(arg) == 0)
		print_error("Empty argument", 1);
	nums = ft_split(arg, ' ');
	while (nums[i] != NULL)
	{
		if (is_valid_num(nums[i]) == 0)
		{
			free_matrix(nums);
			print_error("Invalid argument", 1);
		}
		i++;
	}
	return (nums);
}

static void	check_multiple_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_valid_num(argv[i]) == 0)
			print_error("Invalid argument", 1);
		i++;
	}
}

void	check_args(int argc, char **argv, t_ps *ps)
{
	ps->args = NULL;
	if (argc < 2)
		print_error("No arguments", 1);
	if (argc == 2)
		ps->args = check_single_arg(argv[1]);
	else
	{
		ps->args = &argv[1];
		check_multiple_args(argc, argv);
	}
}
