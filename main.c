/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staut <staut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:27:33 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/18 02:19:53 by staut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_content(int content) { ft_printf(1, "%d\n", content); }

int	main(int argc, char **argv)
{
	t_push_swap	data;
	double disorder;

	handle_initialization_data(&data);
	if (argc <= 1)
		return (0);
	if (!parse_flag(argv, &data))
	{
		handle_free_data(&data);
		return (0);
	}
	dlst_iter(*data.stack_a, &print_content);
	disorder = compute_disorder(&data);
	print_disorder(disorder);
	set_stack_indexes(data.stack_a);
	handle_free_data(&data);
	return (0);
}
