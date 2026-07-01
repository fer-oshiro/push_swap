/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:05:30 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/05/27 16:02:02 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*c;

	i = 0;
	p = dest;
	c = src;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		p[i] = c[i];
		i++;
	}
	return (dest);
}
