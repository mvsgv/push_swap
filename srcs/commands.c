/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariamevissargova <mariamevissargova@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:07:18 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/13 17:28:03 by mariameviss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

// void	swap(t_stack **head)
// {
// 	if (!*head || !(*head)->next)
// 		return ;
// 	*head = (*head)->next;
// 	(*head)->prev->prev = *head;
// 	(*head)->prev->prev = (*head)->next;
// 	if ((*head)->next)
// 		(*head)->next->prev = (*head)->prev;
// 	(*head)->next = (*head)->prev;
// 	(*head)->prev = NULL;
// }
void swap(t_stack **head)
{
    t_stack *first;
    t_stack *second;

    if (!*head || !(*head)->next)
        return;
    
    first = *head;
    second = first->next;

    first->next = second->next;
    if (second->next)
        second->next->prev = first;

    second->prev = NULL;
    second->next = first;
    first->prev = second;

    *head = second;
}

// void	rotate(t_stack **stack)
// {
// 	t_stack	*last_node;

// 	if (!*stack || !(*stack)->next)
// 		return ;
// 	last_node = stack_last(*stack);
// 	last_node->next = *stack;
// 	*stack = (*stack)->next;
// 	(*stack)->prev = NULL;
// 	last_node->next->prev = last_node;
// 	last_node->next->next = NULL;
// }
void rotate(t_stack **stack)
{
    t_stack *last_node;
    t_stack *first_node;

    if (!*stack || !(*stack)->next)
        return;

    first_node = *stack;
    last_node = stack_last(*stack);

    *stack = first_node->next;
    (*stack)->prev = NULL;
    first_node->next = NULL;
    last_node->next = first_node;
    first_node->prev = last_node;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*second_last_node;
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = stack_last(*stack);
	second_last_node = last_node->prev;
	
	second_last_node->next = NULL;
	last_node->prev = NULL;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	*stack= last_node;
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}
