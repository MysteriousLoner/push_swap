/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 03:53:24 by yalee             #+#    #+#             */
/*   Updated: 2023/04/06 04:01:31 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*values;
	int	*index;
	int	temp_value;
	int	total;
	int	steps;
}		t_stack;

typedef struct s_stacks
{
	t_stack	stack_a;
	t_stack	stack_b;
}		t_stacks;

void	ini_stack(t_stack *stack, char **argv, int argc);
void	pa(t_stacks *stacks, int i);
void	p_fill(t_stack *stack);
void	sa(t_stacks *stacks, int i);
void	sb(t_stacks *stacks, int i);
void	ss(t_stacks *stacks, int i);
void	pa(t_stacks *stacks, int i);
void	pb(t_stacks *stacks, int i);
void	ra(t_stacks *stacks, int j);
void	rb(t_stacks *stacks, int j);
void	rr(t_stacks *stacks, int i);
void	rra(t_stacks *stacks, int j);
void	rrb(t_stacks *stacks, int j);
void	rrr(t_stacks *stacks, int i);
void	indexing(t_stack *stack);
void	morph_vals(t_stack *stack);
int		is_sorted(t_stacks *stacks);
void	radix(t_stacks *stacks);
int		find_max(t_stack stack);
void	check(t_stacks stacks);
void	check_args(int argc, char **argv);
void	ft_free(char **dar);
void	ft_error(char *msg);
void	simple_sort(t_stacks *stacks);
int		get_distance(t_stack *stack);
int		*arcpy(int *array, int len);
int		get_min(t_stacks *stacks);
int		get_sec_min(t_stacks *stacks);
void	sort_3(t_stacks *stacks);
void	sort_4(t_stacks *stacks);
void	sort_5(t_stacks *stacks);
void	filler(t_stacks *stacks, int *min, int *next_min);
void	simple_sort(t_stacks *stacks);
#endif