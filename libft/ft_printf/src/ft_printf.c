/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staut <staut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:14:26 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/13 15:59:27 by staut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_chose_format(int fd, char param, va_list *args)
{
	if (param == 'c')
		return (ft_printf_char(fd, va_arg(*args, int)));
	else if (param == 's')
		return (ft_printf_string(fd, va_arg(*args, char *)));
	else if (param == 'p')
		return (ft_printf_pointer(fd, va_arg(*args, void *)));
	else if (ft_strchr("di", param))
		return (ft_printf_digit(fd, va_arg(*args, int)));
	else if (ft_strchr("u", param))
		return (ft_printf_unsigned_digit(fd,
				va_arg(*args, unsigned int)));
	else if (ft_strchr("x", param))
		return (ft_printf_hex(fd, va_arg(*args, unsigned int), 0));
	else if (ft_strchr("X", param))
		return (ft_printf_hex(fd, va_arg(*args, unsigned int), 1));
	else if (ft_strchr("%", param))
	{
		ft_putstr_fd("%", fd);
		return (1);
	}
	return (0);
}

int	ft_printf(int fd, const char *format, ...)
{
	int		i;
	int		res;
	va_list	args;
	char	*flags;

	va_start(args, format);
	flags = "cspdiuxX%";
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr(flags, format[i + 1]))
		{
			i++;
			res += ft_chose_format(fd, format[i], &args);
		}
		else
		{
			ft_putchar_fd(format[i], fd);
			res++;
		}
		i++;
	}
	va_end(args);
	return (res);
}
