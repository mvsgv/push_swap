/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariamevissargova <mariamevissargova@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:49:01 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/13 18:01:59 by mariameviss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

bool	if_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	my_index(t_stack *stack)
{
	int	i;
	int	divised;

	i = 0;
	if (!stack)
		return ;
	divised = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= divised)
			stack->above_divised = true;
		else
			stack->above_divised = false;
		stack = stack->next;
		i++;
	}
}

void	find_target_a(t_stack *a, t_stack *b)
{
	t_stack	*new_b;
	t_stack	*target;
	int		match;

	if (!b)
	{
		while (a)
		{
			a->target = NULL;
			a = a->next;
		}
		return;
	}
	while (a)
	{
		match = INT_MIN;
		new_b = b;
		target = NULL;
		while (new_b)
		{
			if (new_b->nbr < a->nbr && new_b->nbr > match)
			{
				match = new_b->nbr;
				target = new_b;
			}
			new_b = new_b->next;
		}
		if (!target)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	cost_analysis(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_divised))
			a->cost = len_a - (a->index);
		if (a->target->above_divised)
			a->cost += a->target->index;
		else
			a->cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	my_index(a);
	my_index(b);
	find_target_a(a, b);
	cost_analysis(a, b);
	cheapest_moves(a);
}
