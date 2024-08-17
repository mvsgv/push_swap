/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:28:51 by mavissar          #+#    #+#             */
/*   Updated: 2024/08/17 16:09:21 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_hexa(unsigned int nbr, char *chars);
int		ft_putnbr_hexa(uintptr_t nbr);
int		ft_putnbr(int nbr);
int		ft_putunsigned(unsigned int nbr);
int		ft_printf(const char *str, ...);
int		ft_convert(va_list prm, const char format);

int		ft_print_s(char *str);
int		ft_print_x(unsigned int nbr, int x);
int		ft_print_p(uintptr_t nbr);
int		ft_print_d(int nbr);
int		ft_print_c(char c);
void	ft_putchar(char c);

// char	**ft_split(char *s, char c);

#endif