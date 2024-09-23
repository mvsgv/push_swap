/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariamevissargova <mariamevissargova@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:26:16 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/23 07:37:58 by mariameviss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

int	ft_strlen(const char *s)
{
	int i;
	i = 0;
	while(s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - 48);
	return (res * neg);
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