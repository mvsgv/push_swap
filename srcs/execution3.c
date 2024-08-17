/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:16:58 by mavissar          #+#    #+#             */
/*   Updated: 2024/08/17 16:32:52 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa/n");
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb/n");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss/n");
}
