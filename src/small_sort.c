/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:19:39 by yalee             #+#    #+#             */
/*   Updated: 2023/04/06 04:01:57 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sort_3(t_stacks *stacks)
{
	int		min;
	int		next_min;

	filler(stacks, &min, &next_min);
	if (is_sorted(stacks))
		return ;
	if (min == 2 && next_min == 0)
	{
		sa(stacks, 1);
		ra(stacks, 1);
	}
	else if (next_min == 1 && min == 0)
	{
		sa(stacks, 1);
		rra(stacks, 1);
	}
	else if (min == 1)
	{
		if (next_min == 2)
			sa(stacks, 1);
		else
			ra(stacks, 1);
	}
	else
		rra(stacks, 1);
}

void	sort_4(t_stacks *stacks)
{
	int	distance;

	if (is_sorted(stacks))
		return ;
	distance = get_distance(&stacks->stack_a);
	if (distance == 1)
		ra(stacks, 1);
	else if (distance == 2)
	{
		ra(stacks, 1);
		ra(stacks, 1);
	}
	else if (distance == 3)
		rra(stacks, 1);
	if (is_sorted(stacks))
		return ;
	pb(stacks, 1);
	sort_3(stacks);
	pa(stacks, 1);
}

void	sort_5(t_stacks *stacks)
{
	int	distance;

	distance = get_distance(&stacks->stack_a);
	if (distance == 1)
		ra(stacks, 1);
	else if (distance == 2)
	{
		ra(stacks, 1);
		ra(stacks, 1);
	}
	else if (distance == 3)
	{
		rra(stacks, 1);
		rra(stacks, 1);
	}
	else if (distance == 4)
		rra(stacks, 1);
	if (is_sorted(stacks))
		return ;
	pb(stacks, 1);
	sort_4(stacks);
	pa(stacks, 1);
}

void	simple_sort(t_stacks *stacks)
{
	int	size;

	size = stacks->stack_a.total + 1;
	if (is_sorted(stacks) || size == 0 || size == 1)
		return ;
	if (size == 2)
		sa(stacks, 1);
	else if (size == 3)
		sort_3(stacks);
	else if (size == 4)
		sort_4(stacks);
	else if (size == 5)
		sort_5(stacks);
}
