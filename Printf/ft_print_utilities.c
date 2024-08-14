/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:09:30 by mavissar          #+#    #+#             */
/*   Updated: 2024/05/29 14:48:03 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(uintptr_t nbr)
{
	int	count;

	count = 0;
	count += ft_print_s("0x");
	if (count < 0)
		return (-1);
	count += ft_putnbr_hexa(nbr);
	if (count < -1)
		return (-1);
	return (count);
}

int	ft_print_d(int nbr)
{
	int	count;

	count = 0;
	count += ft_putnbr(nbr);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_print_x(unsigned int nbr, int x)
{
	char	*c;

	if (x == 'x')
		c = "0123456789abcdef";
	else
		c = "0123456789ABCDEF";
	return (ft_hexa(nbr, c));
}

int	ft_print_c(char c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
