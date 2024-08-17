/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:26:54 by mavissar          #+#    #+#             */
/*   Updated: 2024/05/29 14:45:50 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int nbr, char *chars)
{
	int		count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_hexa(nbr / 16, chars);
		count += ft_hexa(nbr % 16, chars);
	}
	else
		count += ft_print_c(chars[nbr]);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_putnbr_hexa(uintptr_t nbr)
{
	char	*chars;
	int		count;

	chars = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
	{
		count += ft_putnbr_hexa(nbr / 16);
		count += ft_putnbr_hexa(nbr % 16);
	}
	else
		count += ft_print_c(chars[nbr]);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_putnbr(int nbr)
{
	int		count;

	count = 0;
	if (nbr == -2147483648)
		count += ft_print_s("-2147483648");
	else if (nbr < 0)
	{
		count += ft_print_c('-');
		nbr *= -1;
		count += ft_putnbr(nbr);
	}
	else
	{
		if (nbr > 9)
		{
			count += ft_putnbr(nbr / 10);
			count += ft_putnbr((nbr % 10));
		}
		else
			count += ft_print_c(nbr + 48);
	}
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_putunsigned(unsigned int nbr)
{
	unsigned int		count;

	count = 0;
	if (nbr >= 10)
	{
		count += ft_putnbr(nbr / 10);
		count += ft_putnbr(nbr % 10);
	}
	else
		count += ft_print_c(nbr + 48);
	if (nbr < 0)
		return (-1);
	return (count);
}
