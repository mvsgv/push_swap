/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:20:51 by mavissar          #+#    #+#             */
/*   Updated: 2024/07/19 12:45:40 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long    ft_atol(const char *s)
{
    int         neg;
    long        nb; 
    
    neg = 1;
    nb = 0;
    while (*s >= 9 && *s <= 13 || *s == 32 || *s == '+')
        s++;
    if (*s == '-')
    {
        neg *= -1;
        s++;
    }
    while (*s >= 48 && *s <= 57)
        nb = nb * 10 + (*s++ - '0');
    return (nb * neg);
}

// //to know how far i am from 0 in case my nb is neg
// int     ft_abolute(int nb)
// {
//     if (nb < 0)
//         nb *= -nb;
//     return (nb);
// }

void    free_stack(t_stack **stack)
{
    t_stack temp;

    if (!stack || !*stack)
        return (NULL);
    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
    *stack = NULL;
}
