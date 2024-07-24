/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:27:29 by mavissar          #+#    #+#             */
/*   Updated: 2024/07/19 13:17:06 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     stack_len(t_stack *stack)
{
    int     count;

    count = 0;
    if (!stack)
        return (0);
    while (stack)
    {
        stack = stack->next;
        count++;
    }
    return (count);
}

t_stack     *stack_last(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

void    init_stack_a(t_stack **a, char **argv)
{
    long    n;
    int     i;

    i = 0;
    while (argv[i])
    {
        if (ft_error(argv[i]))
            free_errors(a);
        n = ft_atol(argv[i]);
        if (n > INT_MAX || n < INT_MIN)
            free_errors(a);
        if (ft_duplicated(*a, (int)n))
            free_errors(a, (int)n);
        append_node(a, (int)n);
        i++;
    }
}
static void append_node(t_stack **stack, int n)
{
    t_stack     *node; //new node 
    t_stack     *last_node;

    if (!stack)
        return ;
    node = malloc(sizeof(t_stack));
    if (!node)
        return ;
    node->next = NULL;
    node->nbr = n;
    if (!(*stack)) //if the stack is empty then our new node will be the only node,the * will point to my new node + we set the previous pointer to null
    {
        *stack = node;
        node->prev = NULL;
    }
    else //if stack not empty, we find last node of stack and we add to it the new node
    {
        last_node = find_last(*stack);
        last_node->next = node;
        node->prev =last_node;
    }
}

void    cheapest_moves(t_stack *stack)
{
    long    cheapest_value;
    t_stack *cheapest_node;

    if (!stack)
        return ;
    cheapest_value = LONG_MAX;
    while (stack)
    {
        if (stack->cost < cheapest_value)
        {
            cheapest_value = stack->cost;
            cheapest_value = stack;
        }
        stack = stack->next;
    }
    cheapest_node->cheapest = true;
}