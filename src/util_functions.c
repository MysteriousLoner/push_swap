/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:07:38 by yalee             #+#    #+#             */
/*   Updated: 2023/04/06 03:47:45 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	check(t_stacks stacks)
{
	int	i;

	i = stacks.stack_a.total;
	printf("-----------------------------------\nstack_a\n");
	while (i >= 0)
	{
		printf("index: %i number: %i\n", i, stacks.stack_a.values[i]);
		i--;
	}
	i = stacks.stack_b.total;
	printf("stack_b\n");
	while (i >= 0)
	{
		printf("%i\n", stacks.stack_b.values[i]);
		i--;
	}
	printf("---------------------------------------\n");
}

int	find_max(t_stack stack)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i <= stack.total)
	{
		if (stack.values[i] > max)
			max = stack.values[i];
		i++;
	}
	return (max);
}

int	get_distance(t_stack *stack)
{
	int	min_index;
	int	i;

	i = 1;
	min_index = stack->values[0];
	while (i <= stack->total)
	{
		if (stack->values[i] < min_index)
			min_index = stack->values[i];
		i++;
	}
	i = 0;
	while (i <= stack->total)
	{
		if (min_index == stack->values[i])
			return (stack->total - i);
		i++;
	}
	return (stack->total);
}

void	ft_free(char **dar)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = dar;
	while (dar[i])
	{
		free(dar[i]);
		i++;
	}
	free(tmp);
}

int	*arcpy(int *array, int len)
{
	int	i;
	int	*ret;

	i = 0;
	ret = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		ret[i] = array[i];
		i++;
	}
	return (ret);
}
