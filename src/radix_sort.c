/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:42:43 by yalee             #+#    #+#             */
/*   Updated: 2023/04/06 03:32:43 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = stacks->stack_a.total;
	while (i > 0)
	{
		if (stacks->stack_a.values[i] > stacks->stack_a.values[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	has_0_at_x(t_stack stack, int shift)
{
	int	i;

	i = 0;
	while (i <= stack.total)
	{
		if (((stack.values[i] >> shift) & 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	mass_pa(t_stacks *stacks)
{
	while (stacks->stack_b.total != -1)
		pa(stacks, 1);
}

int	near_top(t_stack stack, int shift)
{
	int	i;

	i = 0;
	while (i <= stack.total)
	{
		if (((stack.values[i] >> shift) & 1) == 0)
		{
			if (i >= stack.total / 2)
				return (1);
			return (0);
		}
		i++;
	}
	return (0);
}

void	radix(t_stacks *stacks)
{
	int			size;
	int			max_num;
	int			i;
	int			j;
	static int	max_bits;

	size = stacks->stack_a.total + 1;
	max_num = find_max(stacks->stack_a);
	while ((max_num >> max_bits) != 0)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stacks->stack_a.values[stacks->stack_a.total] >> i) & 1) == 1)
				ra(stacks, 1);
			else
				pb(stacks, 1);
			j++;
		}
		mass_pa(stacks);
		i++;
	}
}
