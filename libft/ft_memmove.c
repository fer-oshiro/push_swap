/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:20:11 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/05/19 17:30:25 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*c;

	p = dest;
	c = src;
	if (!dest && !src)
		return (dest);
	if (p > c)
	{
		while (n > 0)
		{
			n--;
			p[n] = c[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
