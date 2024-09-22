/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariamevissargova <mariamevissargova@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:26:16 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/18 15:28:30 by mariameviss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

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
	int		l;
	int		l2;
	int		ct;
	char	*str;

	l2 = ft_strlen(s1);
	l = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2 || l < 0)
		return (NULL);
	str = ft_malloc(l + 1, sizeof(char));
	if (!str)
		return (NULL);
	ct = -1;
	while (++ct < l)
	{
		if (ct < l2)
			str[ct] = s1[ct];
		else
			str[ct] = s2[ct - l2];
	}
	str[l] = '\0';
	return (str);
}
