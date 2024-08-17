/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:28:56 by mavissar          #+#    #+#             */
/*   Updated: 2024/05/29 13:56:35 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!str)
	{
		tmp = "(null)";
		while (tmp[i])
		{
			if (ft_print_c(tmp[i]) == -1)
				return (-1);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			if (ft_print_c(str[i]) == -1)
				return (-1);
			i++;
		}
	}
	return (i);
}
