/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:47:35 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/06/05 15:36:40 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_long(unsigned long num)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ft_puthex_long(num / 16);
	ft_putchar_fd(base[num % 16], 1);
	count++;
	return (count);
}

int	ft_printf_pointer(va_list args)
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
	count += ft_puthex_long(ptr) + 2;
	return (count);
}
