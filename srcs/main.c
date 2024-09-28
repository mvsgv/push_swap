/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:51:32 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/28 11:34:41 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

static void	exit_error_argv(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	do_this_shit(t_stack **a, t_stack **b)
{
	if (!if_stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, false);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stack(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	args = NULL;
	if (argc > 1)
	{
		if (argc == 2)
		{
			args = ft_split(argv[1], ' ');
			if (!args || !args[0])
				exit_error_argv(NULL, NULL);
			init_stack_a(&a, args);
		}
		else
			init_stack_a(&a, argv + 1);
		do_this_shit(&a, &b);
		free_stack(&a);
		return (0);
	}
	else
		return (1);
}
