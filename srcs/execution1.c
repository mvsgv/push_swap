/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:12:32 by mavissar          #+#    #+#             */
/*   Updated: 2024/08/17 16:32:44 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa/n");
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb/n");
}

void	rra(t_stack **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		ft_printf("rra/n");
}

void	rrb(t_stack **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		ft_printf("rrb/n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		ft_printf("rrr/n");
}
