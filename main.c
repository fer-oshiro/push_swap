/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:27:33 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/10 11:36:40 by aschulz-         ###   ########.fr       */
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
	printf("%f", disorder);
	handle_free_data(&data);
	return (0);
}
