/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:24:08 by yalee             #+#    #+#             */
/*   Updated: 2023/04/06 03:31:40 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include <stdio.h>

int	is_single(char *argv)
{
	long	i;
	int		flag;

	i = 0;
	flag = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			ft_error("Error");
		if (argv[i] == ' ')
			flag = 1;
		i++;
	}
	if (flag == 1)
		return (0);
	i = ft_atoi(argv);
	if (i < -2147483648 || i > 2147483647)
		ft_error("Error");
	return (1);
}

void	sort(t_stacks *stacks)
{
	int	size;

	size = stacks->stack_a.total;
	if (size <= 4)
		simple_sort(stacks);
	else
		radix(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**ini;

	ini = NULL;
	if (argc < 2)
		return (0);
	check_args(argc, argv);
	ini_stack(&stacks.stack_a, argv, argc);
	ini_stack(&stacks.stack_b, ini, argc);
	indexing(&stacks.stack_a);
	if (is_sorted(&stacks))
	{
		free(stacks.stack_a.values);
		free(stacks.stack_b.values);
		free(stacks.stack_a.index);
		return (0);
	}
	sort(&stacks);
	free(stacks.stack_a.values);
	free(stacks.stack_b.values);
	free(stacks.stack_a.index);
}
