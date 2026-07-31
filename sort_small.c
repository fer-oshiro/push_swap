/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 00:00:00 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/29 00:00:00 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_node_to_top(t_push_swap *data, t_node *target)
{
	int	cost;

	cost = rotation_cost(data->stack_a, target);
	while (cost > 0)
	{
		op_ra(data);
		cost--;
	}
	while (cost < 0)
	{
		op_rra(data);
		cost++;
	}
}

static void	sort_2(t_push_swap *data)
{
	t_node	*first;
	t_node	*second;

	first = data->stack_a->start;
	second = first->next;
	if (first->index > second->index)
		op_sa(data);
}

static void	sort_3(t_push_swap *data)
{
	t_node	*max;
	int		max_position;

	max = stack_max(data->stack_a);
	max_position = stack_position(data->stack_a, max);
	if (max_position == 0)
		op_ra(data);
	else if (max_position == 1)
		op_rra(data);
	if (data->stack_a->start->index
		> data->stack_a->start->next->index)
		op_sa(data);
}

static void	sort_4(t_push_swap *data)
{
	t_node	*min;

	min = stack_min(data->stack_a);
	move_node_to_top(data, min);
	op_pb(data);
	sort_3(data);
	op_pa(data);
}

static void	sort_5(t_push_swap *data)
{
	t_node	*min;

	min = stack_min(data->stack_a);
	move_node_to_top(data, min);
	op_pb(data);
	min = stack_min(data->stack_a);
	move_node_to_top(data, min);
	op_pb(data);
	sort_3(data);
	op_pa(data);
	op_pa(data);
}
