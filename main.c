/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:27:33 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/09 18:17:37 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_content(void *content)
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
	if (!parse_flag(argc, argv, &data))
		return (0);
	ft_lstiter(data.stack_a->start, &print_content);
	return (0);
}
