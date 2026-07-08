/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:12:18 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/08 10:53:20 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(int fd, const char *format, ...);
int	ft_printf_char(int fd, va_list args);
int	ft_printf_string(int fd, va_list args);
int	ft_printf_pointer(int fd, va_list args);
int	ft_printf_digit(int fd, va_list args);
int	ft_printf_unsigned_digit(int fd, va_list args);
int	ft_printf_hex(int fd, va_list args, int is_upper);

#endif