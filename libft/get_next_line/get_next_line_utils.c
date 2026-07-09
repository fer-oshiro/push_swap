/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:06:24 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/08 16:28:40 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*str_join;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	str_join = malloc((len1 + len2 + 1) * sizeof(char));
	i = -1;
	while (s1[++i])
		str_join[i] = s1[i];
	while (*s2)
	{
		str_join[i] = *s2;
		s2++;
		i++;
	}
	str_join[i] = '\0';
	return (str_join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;
	size_t		s_len;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	size_t	total_size;
	char	*ptr;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr != NULL)
	{
		while (total_size > 0)
		{
			total_size--;
			ptr[total_size] = 0;
		}
	}
	return (ptr);
}
