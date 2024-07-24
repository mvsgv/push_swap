/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:51:32 by mavissar          #+#    #+#             */
/*   Updated: 2024/07/19 10:05:12 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
    t_stack     *a;
    t_stack     *b;
    
    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    init_stack_a(&a, argv + 1);
    if (!if_stack_sorted(a))
    {
        if (stack_len(a == 2))
            sa(&a, false);
        else if (stack_len(a) == 3)
            sort_three(&a, &b);
        else
            sort_stacks(&a, &b);
    }
    free_stack(&a);
    return (0);
}