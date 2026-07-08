/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:41:21 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/08 13:44:40 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	count_words(char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_space(*str) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_space(*str))
			in_word = 0;
		str++;
	}
	return (count);
}

static char	*get_next_word(char **str)
{
	char	*word;
	char	*start;
	int		len;
	int		i;

	while (**str && is_space(**str))
		(*str)++;
	start = *str;
	while (**str && !is_space(**str))
		(*str)++;
	len = *str - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_whitespace(char *token)
{
	char	**res;
	int		words;
	int		i;

	if (!token)
		return (NULL);
	words = count_words(token);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < words)
	{
		res[i] = get_next_word(&token);
		if (!res[i])
		{
			while (i > 0)
				free(res[--i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_free_split(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}
