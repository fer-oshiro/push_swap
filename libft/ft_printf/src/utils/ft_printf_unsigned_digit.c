/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_digit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:22:44 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/08 11:42:27 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_putnbr(int fd, unsigned int n)
{
	char			c;
	unsigned int	count;

	count = 0;
	if (n >= 10)
		count += ft_unsigned_putnbr(fd, n / 10);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	count++;
	return (count);
}

int	ft_printf_unsigned_digit(int fd, va_list args)
{
	unsigned int	numb;

	numb = va_arg(args, unsigned int);
	return (ft_unsigned_putnbr(fd, numb));
}
