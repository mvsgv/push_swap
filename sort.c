/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:54:13 by mavissar          #+#    #+#             */
/*   Updated: 2024/07/19 13:21:49 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack **a)
{
    t_stack     *biggest_nb;//in a stack of 3 we look for the bgst_nb

    biggest_nb = find_max(*a);
    if (biggest_nb == *a) //if the biggest nb is at the top we rotate a
        ra(a, false);
    else if ((*a)->next == biggest_nb)//if the 2nd node is the biggest nb we rra
        rra(a, false);
    if ((*a)->nbr > (*a)->next->nbr)//we check if top is larger if yes we sa
        sa(a, false);
}
void    move_a_to_b(t_stack **a, t_stack **b)
{
    
}

void    sort_stack(t_stack **a, t_stack **b)
{
    int     len;
    
    len = stack_len(*a);
    if (len-- > 3 && !if_stack_sorted(*a))
        pb(b, a, false);
    if (len-- > 3 && !if_stack_sorted(*a))
        pb(b, a, false);
    while (len-- > 3 && !if_stack_sorted(*a))
    {
        init_node_a(*a, *b);
        move_a_to_b(*a, *b);
    }
    sort_three(a);
    while (*b)
    {
        init_node_b(*a, *b);
        move_b_to_a(a, b);
    }
    my_index(*a);
    small_to_top(a);
}