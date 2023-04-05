/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:49:22 by yalee             #+#    #+#             */
/*   Updated: 2023/04/06 03:30:04 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	rrr(t_stacks *stacks, int i)
{
	if (i == 1)
	{
		rra(stacks, 0);
		rrb(stacks, 0);
		printf("rrr\n");
	}
	else
	{
		rra(stacks, 0);
		rrb(stacks, 0);
	}
}
