/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:46:58 by yalee             #+#    #+#             */
/*   Updated: 2023/04/06 03:29:50 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sa(t_stacks *stacks, int i)
{
	if (stacks->stack_a.total == 0 || stacks->stack_a.total == -1)
		return ;
	stacks->stack_a.temp_value = stacks->stack_a.values
	[stacks->stack_a.total];
	stacks->stack_a.values[stacks->stack_a.total]
		= stacks->stack_a.values[stacks->stack_a.total - 1];
	stacks->stack_a.values[stacks->stack_a.total - 1]
		= stacks->stack_a.temp_value;
	if (i == 1)
		printf("sa\n");
}

void	sb(t_stacks *stacks, int i)
{
	if (stacks->stack_b.total == 0 || stacks->stack_b.total == -1)
		return ;
	stacks->stack_b.temp_value = stacks->stack_b.values
	[stacks->stack_b.total - 1];
	stacks->stack_b.values[stacks->stack_b.total - 1]
		= stacks->stack_b.values[stacks->stack_b.total - 2];
	stacks->stack_b.values[stacks->stack_b.total - 2]
		= stacks->stack_b.temp_value;
	if (i == 1)
		printf("sb\n");
}

void	ss(t_stacks *stacks, int i)
{
	if (i == 1)
	{
		sa(stacks, 0);
		sb(stacks, 0);
		printf("ss\n");
	}
	else
	{
		sa(stacks, 0);
		sb(stacks, 0);
	}
}

void	pa(t_stacks *stacks, int i)
{
	if (stacks->stack_b.total == -1)
		return ;
	stacks->stack_a.total++;
	stacks->stack_a.values[stacks->stack_a.total]
		= stacks->stack_b.values[stacks->stack_b.total];
	stacks->stack_b.total--;
	stacks->stack_a.steps++;
	if (i == 1)
		printf("pa\n");
}

void	pb(t_stacks *stacks, int i)
{
	if (stacks->stack_a.total == -1)
		return ;
	stacks->stack_b.total++;
	stacks->stack_b.values[stacks->stack_b.total]
		= stacks->stack_a.values[stacks->stack_a.total];
	stacks->stack_a.total--;
	stacks->stack_a.steps++;
	if (i == 1)
		printf("pb\n");
}
