/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:49:01 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/25 19:11:20 by mavissar         ###   ########.fr       */
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

t_stack	*find_target_in_b(t_stack *a, t_stack *b)
{
	t_stack	*new_b;
	t_stack	*target;
	int		match;

	new_b = b;
	target = NULL;
	match = INT_MIN;
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
		target = find_max(b);
	return (target);
}

void	find_target_a(t_stack *a, t_stack *b)
{
	while (a)
	{
		if (!b)
			a->target = NULL;
		else
			a->target = find_target_in_b(a, b);
		a = a->next;
	}
}

void	cost_analysis(t_stack *a, t_stack *b)
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
