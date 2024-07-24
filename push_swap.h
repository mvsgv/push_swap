/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>    å     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:44:02 by mavissar          #+#    #+#             */
/*   Updated: 2024/07/04 16:16:35 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
    int     nbr;
    int     index;
    int     cost;
    bool    above_divised;
    bool    cheapest;
    struct s_stack  *target;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;

*//utils//*
bool    if_stack_sorted(t_stack *stack);
void    my_index(t_stack *stack);
int     stack_len(t_stack *stack);
t_stack     *stack_last(t_stack *stack);
void    init_stack_a(t_stack **a, char **argv);
void    cheapest_moves(t_stack *stack);
void    free_stack(t_stack **stack);

*//init//*
void    init_nodes_a(t_stack *a, t_stack *b);


*//sort//*
void    sort_three(t_stack **a);
void    sort_stack(t_stack **a, t_stack **b);
void    move_a_to_b(t_stack **a, t_stack **b);

*//rest//*
char **split(char *s, char c);
#endif