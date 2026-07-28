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

	init_data(&data);
	if (argc <= 1)
		return (0);
	if (!parse_flag(argv, &data))
	{
		free_data(&data);
		return (0);
	}
	disorder = compute_disorder(&data);
	set_stack_indexes(data.stack_a);
	print_benchmark(&data, disorder);
	free_data(&data);
	return (0);
}
