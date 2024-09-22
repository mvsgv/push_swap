/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariamevissargova <mariamevissargova@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:12:32 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/16 15:53:04 by mariameviss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

// void	pb(t_stack **a, t_stack **b, bool print)
// {
// 	push(b, a);
// 	if (!print)
// 		ft_printf("pb\n");
// 		ft_printf("pb: Pushed element from a to b\n");
// }

void pb(t_stack **b, t_stack **a, bool print)
{
    // ft_printf("Before pb: Top of a: %d, Top of b: %d\n",
        // *a ? (*a)->nbr : -1, *b ? (*b)->nbr : -1);
    push(b, a);
    // ("After pb: Top of a: %d, Top of b: %d\n",
    //  ft_printf   *a ? (*a)->nbr : -1, *b ? (*b)->nbr : -1);
    if (!print)
        ft_printf("pb\n");
}

void	rra(t_stack **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
