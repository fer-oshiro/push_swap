/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simples.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:39:11 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/08/03 13:47:46 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_push_swap *data)
{
	int		curr_rotation_cost;
	t_node	*curr_min_node;

	while (data->stack_a->size)
	{
		curr_min_node = stack_min(data->stack_a);
		curr_rotation_cost = rotation_cost(data->stack_a, curr_min_node);
		while (curr_rotation_cost > 0)
		{
			op_ra(data);
			curr_rotation_cost--;
		}
		while (curr_rotation_cost < 0)
		{
			op_rra(data);
			curr_rotation_cost++;
		}
		op_pb(data);
	}
	while (data->stack_b->size)
		op_pa(data);
}
