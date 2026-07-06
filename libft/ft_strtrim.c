/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:46:58 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/05/22 13:26:31 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static void	ft_start_string(size_t *start, char const *s1, char const *set)
{
	*start = 0;
	while (s1[*start] && ft_is_set(s1[*start], set))
		*start += 1;
}

static void	ft_end_string(size_t start, size_t *end,
		char const *s1, char const *set)
{
	*end = ft_strlen(s1) - 1;
	while (*end > start && ft_is_set(s1[*end], set))
		*end -= 1;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	ft_start_string(&start, s1, set);
	if (start == ft_strlen(s1))
	{
		p = malloc(1 * sizeof(char));
		if (!p)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	ft_end_string(start, &end, s1, set);
	p = malloc((end - start + 2) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, &s1[start], end - start + 2);
	return (p);
}
