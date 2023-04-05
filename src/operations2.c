/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:55:56 by yalee             #+#    #+#             */
/*   Updated: 2023/04/06 03:18:15 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ra(t_stacks *stacks, int j)
{
	int	i;

	i = stacks->stack_a.total;
	stacks->stack_a.temp_value = stacks->stack_a.values[i];
	while (i > 0)
	{
		stacks->stack_a.values[i] = stacks->stack_a.values[i - 1];
		i--;
	}
	stacks->stack_a.values[0] = stacks->stack_a.temp_value;
	stacks->stack_a.steps++;
	if (j == 1)
		printf("ra\n");
}

void	rb(t_stacks *stacks, int j)
{
	int	i;

	i = stacks->stack_b.total;
	stacks->stack_b.temp_value = stacks->stack_b.values[i];
	while (i > 0)
	{
		stacks->stack_b.values[i] = stacks->stack_b.values[i - 1];
		i--;
	}
	stacks->stack_b.values[i] = stacks->stack_b.temp_value;
	if (j == 1)
		printf("rb\n");
}

void	rr(t_stacks *stacks, int i)
{
	if (i == 1)
	{
		ra(stacks, 0);
		rb(stacks, 0);
		printf("rr\n");
	}
	else
	{
		ra(stacks, 0);
		rb(stacks, 0);
	}
}

void	rra(t_stacks *stacks, int j)
{
	int	i;

	i = 0;
	stacks->stack_a.temp_value = stacks->stack_a.values[stacks->stack_a.total];
	stacks->stack_a.values[stacks->stack_a.total] = stacks->stack_a.values[0];
	while (i < stacks->stack_a.total - 1)
	{
		stacks->stack_a.values[i] = stacks->stack_a.values[i + 1];
		i++;
	}
	stacks->stack_a.values[i] = stacks->stack_a.temp_value;
	if (j == 1)
		printf("rra\n");
}

void	rrb(t_stacks *stacks, int j)
{
	int	i;

	i = 0;
	stacks->stack_b.temp_value = stacks->stack_b.values[stacks->stack_b.total];
	stacks->stack_b.values[stacks->stack_b.total] = stacks->stack_b.values[0];
	while (i < stacks->stack_b.total)
	{
		stacks->stack_b.values[i] = stacks->stack_b.values[i + 1];
		i++;
	}
	stacks->stack_b.values[i] = stacks->stack_b.temp_value;
	if (j == 1)
		printf("rrb\n");
}
