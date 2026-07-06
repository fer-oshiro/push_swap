/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 10:19:40 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/05/27 19:57:48 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		is_word;

	i = 0;
	is_word = 1;
	while (*s)
	{
		if (*s != c && is_word)
		{
			is_word = 0;
			i++;
		}
		if (*s == c)
			is_word = 1;
		s++;
	}
	return (i);
}

static char	*ft_get_word(char const *s, char c)
{
	int		str_len;
	char	*p;

	str_len = 0;
	while (s[str_len] && s[str_len] != c)
		str_len++;
	p = ft_calloc(sizeof(char), str_len + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s, str_len + 1);
	return (p);
}

static void	ft_free_word(char **p)
{
	int	i;

	if (!p)
		return ;
	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;

	if (!s)
		return (NULL);
	p = ft_calloc(sizeof(char *), ft_count_words(s, c) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			p[i] = ft_get_word(s, c);
			if (!p[i++])
				return (ft_free_word(p), NULL);
			while (*s && *s != c)
				s++;
		}
	}
	return (p);
}
