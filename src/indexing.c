/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:27:26 by yalee             #+#    #+#             */
/*   Updated: 2023/04/06 03:24:28 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	morph_vals(t_stack *stack)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (i <= stack->total)
	{
		j = 0;
		flag = 0;
		while (j <= stack->total && flag == 0)
		{
			if (stack->values[i] == stack->index[j])
			{
				stack->values[i] = j;
				flag = 1;
			}
			j++;
		}
		i++;
	}		
}

void	indexing(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	stack->index = arcpy(stack->values, stack->total + 1);
	while (i <= stack->total)
	{
		j = 0;
		while (j <= stack->total - i - 1)
		{
			if (stack->index[j] > stack->index[j + 1])
			{
				stack->temp_value = stack->index[j];
				stack->index[j] = stack->index[j + 1];
				stack->index[j + 1] = stack->temp_value;
			}
			j++;
		}
		i++;
	}
	morph_vals(stack);
}
