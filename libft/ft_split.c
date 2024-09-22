/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariamevissargova <mariamevissargova@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:59:42 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/13 16:05:21 by mariameviss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

static int	ft_counter(char *s, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		while (s[i] != sep && s[i])
			i++;
		count += 1;
	}
	return (count);
}

static char	*ft_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	while ((s[cursor + len] != c) && s[cursor + len])
		len++;
	next_word = malloc(sizeof(char) * (len + 1));
	if (!next_word)
		return (NULL);
	while (s[cursor] != c && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(char *s, char c)
{
	int		qtt_words;
	char	**array;
	int		i;

	i = 0;
	qtt_words = ft_counter(s, c);
	if (!qtt_words)
		exit(1);
	array = malloc(sizeof(char *) * (size_t)(qtt_words + 2));
	if (!array)
		return (NULL);
	while (qtt_words-- >= 0)
	{
		if (i == 0)
		{
			array[i] = malloc(sizeof(char));
			if (!array[i])
				return (NULL);
			array[i++][0] = '\0';
			continue ;
		}
		array[i++] = ft_next_word(s, c);
	}
	array[i] = NULL;
	return (array);
}
