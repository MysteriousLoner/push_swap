/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:55:34 by yalee             #+#    #+#             */
/*   Updated: 2023/04/06 03:23:53 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

static void	input_instr2(char *input, t_stacks *stacks)
{
	if (ft_strcmp("pb\n", input))
		pb(stacks, 0);
	else if (ft_strcmp("pa\n", input))
		pa(stacks, 0);
	else if (ft_strcmp("sa\n", input))
		sa(stacks, 0);
	else if (ft_strcmp("sb\n", input))
		sb(stacks, 0);
	else if (ft_strcmp("ss\n", input))
		ss(stacks, 0);
	else
	{
		ft_putstr_fd("Error!\n", 1);
		exit(0);
	}
}

void	input_instr(char *input, t_stacks *stacks)
{
	if (ft_strcmp("rra\n", input))
		rra(stacks, 0);
	else if (ft_strcmp("rrb\n", input))
		rrb(stacks, 0);
	else if (ft_strcmp("rrr\n", input))
		rrr(stacks, 0);
	else if (ft_strcmp("ra\n", input))
		ra(stacks, 0);
	else if (ft_strcmp("rb\n", input))
		rb(stacks, 0);
	else if (ft_strcmp("rr\n", input))
		rr(stacks, 0);
	else
		input_instr2(input, stacks);
}

void	do_loop(t_stacks *stacks, char **input)
{
	while (1)
	{
		*input = get_next_line(0);
		if (*input == NULL || ft_strcmp("\n", *input))
		{
			if (is_sorted(stacks) && stacks->stack_b.total == -1)
				ft_putstr_fd("OK\n", 1);
			else
				ft_putstr_fd("KO\n", 1);
			free(*input);
			break ;
		}
		input_instr(*input, stacks);
		free(*input);
	}
	free(stacks->stack_a.values);
	free(stacks->stack_b.values);
	free(stacks->stack_a.index);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		*input;
	char		**ini;

	ini = NULL;
	if (argc < 2)
		return (0);
	check_args(argc, argv);
	ini_stack(&stacks.stack_a, argv, argc);
	ini_stack(&stacks.stack_b, ini, argc);
	indexing(&stacks.stack_a);
	do_loop(&stacks, &input);
	return (0);
}
