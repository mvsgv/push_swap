/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_nodes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:38:46 by mavissar          #+#    #+#             */
/*   Updated: 2024/07/22 13:23:22 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_nodes_a(t_stack *a, t_stack *b)
{
    my_index(a);
    my_index(b);
    find_target(a, b);
    cost_analysis(a, b);
    choose_cheapest(a);
}