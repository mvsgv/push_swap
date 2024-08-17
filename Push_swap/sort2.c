/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:33:48 by mavissar          #+#    #+#             */
/*   Updated: 2024/08/14 17:43:02 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_the_cheapest(*a);
	if (cheapest_node->above_divised && cheapest_node->target->above_divised)
		rotate_both(*a, *b, cheapest_node);
	else if (!(cheapest_node->above_divised
			&& cheapest_node->target->above_divised))
		rev_rot_both(*a, *b, cheapest_node);
	prep_to_push(a, cheapest_node, 'a');
	prep_to_push(b, cheapest_node->target, 'b');
	pb(b, a, false);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_to_push(a, (*b)->target, 'a');
	pa(a, b, false);
}
