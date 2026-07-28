/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 00:00:00 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/28 00:00:00 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	dlst_reverse_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return (FALSE);
	stack->start = stack->start->prev;
	return (TRUE);
}

void	op_rra(t_push_swap *data)
{
	if (!dlst_reverse_rotate(data->stack_a))
		return ;
	data->ops.rra++;
	data->ops.total++;
	ft_printf(1, "rra\n");
}

void	op_rrb(t_push_swap *data)
{
	if (!dlst_reverse_rotate(data->stack_b))
		return ;
	data->ops.rrb++;
	data->ops.total++;
	ft_printf(1, "rrb\n");
}

void	op_rrr(t_push_swap *data)
{
	t_bool	rotated_a;
	t_bool	rotated_b;

	rotated_a = dlst_reverse_rotate(data->stack_a);
	rotated_b = dlst_reverse_rotate(data->stack_b);
	if (!rotated_a && !rotated_b)
		return ;
	data->ops.rrr++;
	data->ops.total++;
	ft_printf(1, "rrr\n");
}
