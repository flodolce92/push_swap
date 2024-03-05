/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:54:38 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/05 06:42:33 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**check_single_arg(char *arg)
{
	int		i;
	int		j;
	char	**nums;

	i = 0;
	if (ft_strlen(arg) == 0)
		print_error("Empty argument", 1);
	nums = ft_split(arg, ' ');
	while (nums[i] != NULL)
	{
		j = 0;
		if (ft_strlen(nums[i]) == 0)
			print_error("Empty argument", 1);
		while (nums[i][j] != '\0')
		{
			if (!ft_isdigit(nums[i][j])
				&& nums[i][j] != '-' && nums[i][j] != '+')
				print_error("Invalid argument", 1);
			j++;
		}
		i++;
	}
	return (nums);
}

static void	check_multiple_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_strlen(argv[i]) == 0)
			print_error("Empty argument", 1);
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0
				&& argv[i][j] != '-' && argv[i][j] != '+')
				print_error("Invalid argument", 1);
			j++;
		}
		i++;
	}
}

char	**check_args(int argc, char **argv)
{
	char	**nums;

	nums = NULL;
	if (argc < 2)
		print_error("No arguments", 1);
	if (argc == 2)
		nums = check_single_arg(argv[1]);
	else
		check_multiple_args(argc, argv);
	return (nums);
}
