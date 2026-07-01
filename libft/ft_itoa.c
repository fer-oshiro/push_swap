/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:14:13 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/05/28 13:34:24 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		if (n < 0)
			n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*p;
	long	nbr;
	int		len;

	nbr = n;
	len = ft_get_len(nbr);
	p = ft_calloc(sizeof(char), len + 1);
	if (!p)
		return (NULL);
	if (nbr == 0)
		p[0] = '0';
	if (nbr < 0)
	{
		p[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		p[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (p);
}
