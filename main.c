/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:27:33 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/15 10:39:58 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include <stdio.h>

void	print_content(int content)
{
	ft_printf(1, "%d\n", content);
}

int	main(int argc, char **argv)
{
	t_push_swap	data;

	handle_initialization_data(&data);
	if (argc <= 1)
		return (0);
	if (!parse_flag(argv, &data))
	{
		handle_free_data(&data);
		return (0);
	}
	op_pb(&data);
	ft_printf(1, "\n\n\n");
	dlst_iter(*data.stack_a, &print_content);
	ft_printf(1, "\n\n\n");
	dlst_iter(*data.stack_b, &print_content);
	compute_disorder(&data);
	return (0);
}
