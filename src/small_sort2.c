/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 03:40:48 by yalee             #+#    #+#             */
/*   Updated: 2023/04/06 04:03:30 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	get_min(t_stacks *stacks)
{
	int	min;
	int	min_index;
	int	i;

	min = stacks->stack_a.values[0];
	min_index = 0;
	i = 1;
	while (i <= stacks->stack_a.total)
	{
		if (stacks->stack_a.values[i] < min)
		{
			min = stacks->stack_a.values[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	get_sec_min(t_stacks *stacks)
{
	int	i;
	int	j;
	int	f1;
	int	f2;

	i = 0;
	while (i <= stacks->stack_a.total)
	{
		j = 0;
		f1 = 0;
		f2 = 0;
		while (j <= stacks->stack_a.total)
		{
			if (stacks->stack_a.values[i] > stacks->stack_a.values[j])
				f1++;
			if (stacks->stack_a.values[i] < stacks->stack_a.values[j])
				f2++;
			j++;
		}
		if (f1 == 1 && f2 == 1)
			return (i);
		i++;
	}
	return (0);
}

void	filler(t_stacks *stacks, int *min, int *next_min)
{
	*min = get_min(stacks);
	*next_min = get_sec_min(stacks);
}
