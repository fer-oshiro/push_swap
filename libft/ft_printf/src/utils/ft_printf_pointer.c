/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:47:35 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/08 11:13:28 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_long(int fd, unsigned long num)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ft_puthex_long(fd, num / 16);
	ft_putchar_fd(base[num % 16], 1);
	count++;
	return (count);
}

int	ft_printf_pointer(int fd, va_list args)
{
	unsigned long	ptr;
	int				count;

	ptr = va_arg(args, unsigned long);
	count = 0;
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	count += ft_puthex_long(fd, ptr) + 2;
	return (count);
}
