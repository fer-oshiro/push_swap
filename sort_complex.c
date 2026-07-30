/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:49:48 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/30 16:12:36 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_index)
{
	int	max_bit;
	int	max_val;

	max_bit = 0;
	max_val = max_index - 1;
	while ((max_val >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

static void	radix_pass(t_push_swap *data, int bit)
{
	int		index;
	t_node	*curr;

	index = 0;
	while (index < data->size)
	{
		if (((data->stack_a->start->index >> bit) & 1) == 1)
			op_ra(data);
		else
			op_pb(data);
		index++;
	}
	while (data->stack_b->size > 0)
		op_pa(data);
}

void	sort_complex(t_push_swap *data)
{
	int	max_bits;
	int	index;

	max_bits = get_max_bits(data->size);
	index = 0;
	while (index < max_bits)
	{
		radix_pass(data, index);
		index++;
	}
}
