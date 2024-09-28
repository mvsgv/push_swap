/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:38:46 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/25 19:01:21 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

static void	if_a_if_b(t_stack **stack, t_stack *top_node, char stack_name)
{
	if (stack_name == 'a')
	{
		if (top_node->above_divised)
			ra(stack, false);
		else
			rra(stack, false);
	}
	else if (stack_name == 'b')
	{
		if (top_node->above_divised)
			rb(stack, false);
		else
			rrb(stack, false);
	}
}

void	prep_to_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	t_stack	*current;
	bool	found;

	current = *stack;
	found = false;
	while (current)
	{
		if (current == top_node)
		{
			found = true;
			break ;
		}
		current = current->next;
	}
	if (!found)
		return ;
	while (*stack != top_node)
	{
		if_a_if_b(stack, top_node, stack_name);
	}
}

t_stack	*find_min(t_stack *stack)
{
	int		min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*find_max(t_stack *stack)
{
	int		max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	my_index(a);
	my_index(b);
	find_target_a(a, b);
	cost_analysis(a, b);
	cheapest_moves(a);
}
