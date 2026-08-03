/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:51:10 by staut             #+#    #+#             */
/*   Updated: 2026/08/03 13:52:34 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_top_b(t_push_swap *data, int pos)
{
	int	size;

	size = data->stack_b->size;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			op_rb(data);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			op_rrb(data);
			pos++;
		}
	}
}

int	ft_find_max_index_pos(t_stack *stack)
{
	t_node	*curr;
	int		max_idx;
	int		max_pos;
	int		i;

	if (!stack || stack->size == 0)
		return (-1);
	curr = stack->start;
	max_idx = curr->index;
	max_pos = 0;
	i = 0;
	while (i < stack->size)
	{
		if (curr->index > max_idx)
		{
			max_idx = curr->index;
			max_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_pos);
}

void	ft_push_back_to_a(t_push_swap *data)
{
	int	max_pos;

	while (data->stack_b->size > 0)
	{
		max_pos = ft_find_max_index_pos(data->stack_b);
		ft_move_to_top_b(data, max_pos);
		op_pa(data);
	}
}

int	ft_calculate_chunk_size(int len)
{
	if (len <= 100)
		return (15);
	if (len <= 500)
		return (30);
	return (45);
}

void	sort_medium(t_push_swap *data)
{
	int	i;
	int	chunk;

	i = 0;
	chunk = ft_calculate_chunk_size(data->stack_a->size);
	while (data->stack_a->size > 0)
	{
		if (data->stack_a->start->index <= i)
		{
			op_pb(data);
			op_rb(data);
			i++;
		}
		else if (data->stack_a->start->index <= i + chunk)
		{
			op_pb(data);
			i++;
		}
		else
			op_ra(data);
	}
	ft_push_back_to_a(data);
}
