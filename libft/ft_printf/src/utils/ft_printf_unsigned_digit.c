/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_digit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:22:44 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/06/05 15:28:34 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_putnbr(unsigned int n, int fd)
{
	char			c;
	unsigned int	count;

	count = 0;
	if (n >= 10)
		count += ft_unsigned_putnbr(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	count++;
	return (count);
}

int	ft_printf_unsigned_digit(va_list args)
{
	unsigned int	numb;

	numb = va_arg(args, unsigned int);
	return (ft_unsigned_putnbr(numb, 1));
}
