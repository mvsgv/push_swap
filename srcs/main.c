/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariamevissargova <mariamevissargova@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:51:32 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/18 15:34:42 by mariameviss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;

	if (argc > 1) 
	{
		if (argc == 2 && argv[1][0] != '\0')

			argv = ft_split(ft_strjoin("push_swap ", argv[1]), ' ');
		init_stack_a(&a, argv + 1);
		if (!if_stack_sorted(a))
		{
			if (stack_len(a) == 2)
				sa(&a, false);
			else if (stack_len(a) == 3)
				sort_three(&a);
			else
				sort_stack(&a, &b);
		}
		// system("leaks a.out");
		// free_stack(&a);
		return (0);
	}
	else
	{
		// system("leaks a.out");
		return 1;
	}
}
