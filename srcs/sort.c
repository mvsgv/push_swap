/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariamevissargova <mariamevissargova@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:54:13 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/23 09:15:18 by mariameviss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

static void	min_on_top(t_stack **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_divised)
			ra(a, false);
		else
			rra(a, false);
	}
}

t_stack	*get_the_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rr(a, b, false);
	my_index(*a);
	my_index(*b);
}

void	rev_rot_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rrr(a, b, false);
	my_index(*a);
	my_index(*b);
}

// void	sort_stack(t_stack **a, t_stack **b)
// {
// 	int	len;

// 	len = stack_len(*a);
// 	while (len > 3 && !if_stack_sorted(*a))
// 	{
// 			ft_printf("are you here ?");
// 		pb(b, a, false);
// 		len -= 1;
// 	}
// 	// if (len > 3 && !if_stack_sorted(*a))
// 	// {
// 	// 	init_nodes_a(*a, *b);
// 	// 	move_a_to_b(a, b);
// 	// 	len--;
// 	// }
// 	sort_three(a);
// 		ft_printf("are you ?");
// 	while (*b)
// 	{
// 		init_nodes_b(*a, *b);
// 		move_b_to_a(a, b);
// 	}
// 	my_index(*a);
// 	min_on_top(a);
// }

void sort_stack(t_stack **a, t_stack **b)
{
    int len;

    len = stack_len(*a);
    if (len > 3 && !if_stack_sorted(*a))
    {
        pb(b, a, false);
        len -= 1;
	}
	if (len > 3 && !if_stack_sorted(*a))
    {
        pb(b, a, false);
        len -= 1;
    }
	while (len > 3 && !if_stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
		len -=1;
	}
    sort_three(a);
	while (*b)
    {
        init_nodes_b(*a, *b);
	    move_b_to_a(a, b);
    }
    my_index(*a);
    min_on_top(a);
}
