/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:04:38 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/05/19 16:18:56 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	str_len;

	str_len = ft_strlen(s);
	while (str_len > 0)
	{
		if (s[str_len] == (char)c)
			return ((char *)&s[str_len]);
		str_len--;
	}
	if (s[str_len] == (char)c)
		return ((char *)&s[str_len]);
	return (0);
}
