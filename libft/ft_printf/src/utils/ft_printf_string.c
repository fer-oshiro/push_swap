/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:47:35 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/08 12:59:50 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_string(int fd, char *string)
{
	if (!string)
		string = "(null)";
	ft_putstr_fd(string, fd);
	return (ft_strlen(string));
}
