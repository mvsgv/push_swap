/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:49:01 by mavissar          #+#    #+#             */
/*   Updated: 2024/08/14 17:43:14 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool	if_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
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

static void	find_target(t_stack *a, t_stack *b)
{
	t_stack	*new_b;
	t_stack	*target;
	long	match;

	while (a)
	{
		match = LONG_MIN;
		new_b = b;
		while (new_b)
		{
			if (new_b->nbr < a->nbr && new_b->nbr > match)
			{
				match = new_b->nbr;
				target = new_b;
			}
			new_b = new_b->next;
		}
		if (target == LONG_MIN)
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

static long	ft_atol(const char *s)
{
	int		neg;
	long	nb;

	neg = 1;
	nb = 0;
	while (*s >= 9 && *s <= 13 || *s == 32 || *s == '+')
		s++;
	if (*s == '-')
	{
		neg *= -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
		nb = nb * 10 + (*s++ - '0');
	return (nb * neg);
}
