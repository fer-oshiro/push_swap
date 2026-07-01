/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:50:20 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/05/20 17:12:29 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*str_join;

	len = ft_strlen(s1) + ft_strlen(s2);
	str_join = malloc((len + 1) * sizeof(char));
	i = 0;
	while (*s1)
	{
		str_join[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		str_join[i] = *s2;
		s2++;
		i++;
	}
	str_join[i] = '\0';
	return (str_join);
}
