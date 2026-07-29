/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 15:29:35 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/08 11:02:29 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(int fd, int character)
{
	unsigned char	c;

	c = (unsigned char)character;
	ft_putchar_fd(c, fd);
	return (1);
}
