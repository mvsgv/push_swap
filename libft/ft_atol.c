/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:26:16 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/28 12:04:08 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"
#include <stdbool.h>
#include <limits.h>
#include <errno.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long	ft_atol(const char *str)
{
	int		i;
	long	s;
	long	res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			s = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if ((res * s) > INT_MAX)
			return (LONG_MAX);
		if ((res * s) < INT_MIN)
			return (LONG_MIN);
		i++;
	}
	return (res * s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		indent;
	int		length_s1;
	int		length_s2;
	char	*string;

	if (s1 && s2)
	{
		length_s1 = ft_strlen(s1);
		length_s2 = ft_strlen(s2);
		string = (char *)malloc(sizeof(char) * (length_s1 + length_s2 + 1));
		if (string == NULL)
			return (NULL);
		indent = -1;
		while (s1[++indent])
			string[indent] = s1[indent];
		indent = -1;
		while (s2[++indent])
			string[length_s1 + indent] = s2[indent];
		string[length_s1 + indent] = '\0';
		return (string);
	}
	return (NULL);
}
