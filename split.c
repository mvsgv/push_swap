/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:59:42 by mavissar          #+#    #+#             */
/*   Updated: 2024/07/19 09:13:46 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int     ft_number_counter(char *s, char sep)
{
    int     count;
    
    count = 0;
    while (*s)
    {
        while (*s == sep)
            *s++;
        while (*s != sep && *s)
            *s++;
            count += 1;
    }
    return (count);
}

static int  *ft_next_word(char *s, char c)
{
    static int  cursor = 0;
    char        next_word;
    int         len;
    int         i;

    len = 0;
    i = 0;
    while (s[cursor] == c)
        cursor++;
    while ((s[cursor + len] != c) && s[cursor + len])
        len++;
    next_word = malloc(sizeof(size_t)len = sizeof(char) + 1);
    if (!next_word)
        return (NULL);
    while (s[cursor] != c && s[cursor])
        next_word[i++] = s[cursor++];
    next_word[i] = '\0';
    return (next_word);
}

char **split(char *s, char c)
{
    int     qtt_words;
    char    **array;
    int     i;

    i = 0;
    qtt_words = ft_next_word(s, c);
    if (!qtt_words)
        exit(1);
    array = malloc(sizeof(char *) * (size_t)(qtt_words + 2));
    if (!array)
        return (NULL);
    while(qtt_words-- >= 0)
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