/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:27:33 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/09 17:35:53 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printar_content(void *content)
{
	int	num;

	num = (int)(long)content;
	ft_printf(1, "%d\n", num);
}

int	main(int argc, char **argv)
{
	t_push_swap	data;

	handle_initialization_data(&data);
	if (argc <= 1)
		return (0);
	if (!parse_flag(argv, &data))
		return (0);
	ft_lstiter(data.stack_a->start, &printar_content);
	return (0);
}
