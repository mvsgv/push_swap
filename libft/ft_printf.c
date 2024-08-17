/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:47:28 by mavissar          #+#    #+#             */
/*   Updated: 2024/05/29 15:59:54 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(va_list prm, const char format)
{
	int		count;

	count = 0;
	if (format == 'c')
		count += ft_print_c((char) va_arg(prm, int));
	else if (format == 's')
		count += ft_print_s((char *) va_arg(prm, char *));
	else if (format == 'd' || format == 'i')
		count += ft_print_d(va_arg(prm, int));
	else if (format == 'u')
		count += ft_putunsigned(va_arg(prm, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_print_x(va_arg(prm, unsigned int), format);
	else if (format == '%')
		count += ft_print_c('%');
	else if (format == 'p')
		count += ft_print_p(va_arg(prm, unsigned long long));
	else
		count += ft_print_c(format);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_convert(args, str[i + 1]);
			i++;
		}
		else
			count += ft_print_c(str[i]);
		if (count < 0)
			return (-1);
		i++;
	}
	va_end(args);
	return (count);
}
