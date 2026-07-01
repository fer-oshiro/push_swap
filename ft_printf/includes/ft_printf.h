/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:12:18 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/06/05 16:23:07 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);

int	ft_printf_char(va_list args);
int	ft_printf_string(va_list args);
int	ft_printf_pointer(va_list args);
int	ft_printf_digit(va_list args);
int	ft_printf_unsigned_digit(va_list args);
int	ft_printf_hex(va_list args, int is_upper);

#endif