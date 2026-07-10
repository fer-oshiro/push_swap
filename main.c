/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:27:33 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/10 10:19:41 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_content(int content)
{
	ft_printf(1, "%d\n", content);
}

int	main(int argc, char **argv)
{
	t_push_swap	data;
	int disorder;

	handle_initialization_data(&data);
	if (argc <= 1)
		return (0);
	if (!parse_flag(argv, &data))
		return (0);
	dlst_iter(*data.stack_a, &print_content);
	disorder = compute_disorder(&data);
	ft_printf(1, "%f", disorder);
	return (0);
}
