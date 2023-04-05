/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:34:23 by yalee             #+#    #+#             */
/*   Updated: 2023/04/06 03:25:40 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	get_len(char **argv1, int argc)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	if (argc > 2)
	{
		i = 1;
		while (argv1[i])
			i++;
		c = i - 2;
	}
	else
	{
		while (argv1[1][i])
		{
			if (argv1[1][i] == ' ')
				c++;
			i++;
		}
	}
	return (c);
}

void	fill_stack(t_stack *stack, char **argv, int argc)
{
	int		i;
	char	**temp;

	if (argc > 2)
	{
		i = 1;
		while (argv[i])
		{
			stack->values[stack->total - i + 1] = ft_atoi(argv[i]);
			i++;
		}
	}
	else
	{
		temp = ft_split(argv[1], ' ');
		i = 0;
		while (temp[i])
		{
			stack->values[stack->total - i] = ft_atoi(temp[i]);
			i++;
		}
	}
}

void	ini_stack(t_stack *stack, char **argv, int argc)
{
	static int	flag;
	static int	len;

	if (flag != 1)
	{
		stack->total = get_len(argv, argc);
		len = stack->total;
		flag = 1;
	}
	if (argv == NULL)
	{
		stack->total = -1;
		stack->values = (int *)malloc((len + 1) * sizeof(int));
		return ;
	}
	stack->values = (int *)malloc((len + 1) * sizeof(int));
	stack->index = (int *)malloc((len + 1) * sizeof(int));
	fill_stack(stack, argv, argc);
	stack->steps = 0;
}
