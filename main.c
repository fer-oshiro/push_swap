/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staut <staut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:27:33 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/18 02:14:30 by staut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	data;
	double		disorder;

	if (argc <= 1)
		return (0);
	init_data(&data);
	if (!parse_flag(argv, &data))
	{
		ft_putstr_fd("Error\n", 2);
		free_data(&data);
		return (1);
	}
	disorder = compute_disorder(&data);
	if (disorder != 0.0)
	{
		set_stack_indexes(data.stack_a);
		if (data.size <= 3)
			sort_small(&data);
	}
	print_benchmark(&data, disorder);
	free_data(&data);
	return (0);
}
