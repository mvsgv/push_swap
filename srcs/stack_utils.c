/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:27:29 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/28 12:01:43 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

int	stack_len(t_stack *stack)
{
	int		count;
	t_stack	*tmp;

	tmp = stack;
	count = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static void	append_node(t_stack **stack, int n)
{
	t_stack	*last_node;
	t_stack	*node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = stack_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	cheapest_moves(t_stack *stack)
{
	int		cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_node = NULL;
	cheapest_value = INT_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_stack_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_errors(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n == LONG_MAX || n == LONG_MIN || n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (dup_error(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}
