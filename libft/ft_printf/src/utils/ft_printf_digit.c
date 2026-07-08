/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:22:44 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/08 11:07:59 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_digit(int fd, va_list args)
{
	int	numb;

	numb = va_arg(args, int);
	return (ft_putnbr_fd(numb, fd));
}
