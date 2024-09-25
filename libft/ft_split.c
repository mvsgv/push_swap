/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:59:42 by mavissar          #+#    #+#             */
/*   Updated: 2024/09/24 15:43:50 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/push_swap.h"

static char	*free_palestine(char **c)
{
	int	i;

	i = 0;
	while (c[i] != NULL)
	{
		free(c[i]);
		i++;
	}
	return (NULL);
}

static int	number_of_words(char *string, char separator)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (string[index])
	{
		while (string[index] == separator && string[index])
			index++;
		if (string[index] != '\0')
			count++;
		while (string[index] != separator && string[index])
			index++;
	}
	return (count);
}

static char	*word_len(char const *string, char separator)
{
	int		first;
	int		second;
	int		lenght;
	char	*temp;

	lenght = 0;
	first = 0;
	second = 0;
	while (string[first] != separator && string[first])
	{
		first++;
		lenght++;
	}
	temp = malloc(sizeof(char *) * (lenght + 1));
	if (!temp)
		return (NULL);
	while (second < lenght)
	{
		temp[second] = string[second];
		second++;
	}
	temp[second] = '\0';
	return (temp);
}

static char	**make_tab(const char *s, char c, int nbr_words, char **news_s)
{
	int	i;
	int	index;

	i = -1;
	index = 0;
	while (s[index] && i < nbr_words)
	{
		while (s[index] == c && s[index])
			index++;
		if (s[index] != '\0')
		{
			news_s[++i] = word_len(&s[index], c);
			if (news_s[i] == NULL)
				return (free_palestine(news_s), free(news_s), NULL);
		}
		while (s[index] != c && s[index])
			index++;
	}
	return (news_s);
}

char	**ft_split(char *s, char c)
{
	int		nbr_words;
	char	**news_s;

	if (!s)
		return (NULL);
	nbr_words = number_of_words(s, c) + 1;
	news_s = (char **)malloc((nbr_words) * sizeof(char *));
	if (!news_s)
		return (NULL);
	if (make_tab(s, c, nbr_words, news_s) == NULL)
		return (NULL);
	news_s[nbr_words - 1] = NULL;
	return (news_s);
}
