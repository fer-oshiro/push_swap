/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:27:33 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/07 15:33:53 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	printar_content(void *content)
{
	int num = (int)(long)content;
	ft_printf("%d\n", num);
}

int	main(int argc, char **argv)
{
	t_push_swap	data;

	handle_initialization_data(&data);
	if (argc <= 1)
		return (0);
	if (!parse_flag(argc, argv, &data))
		return (0);

	ft_lstiter(data.stack_a->start, &printar_content);
	return (0);
}
