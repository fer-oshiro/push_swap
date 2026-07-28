/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 10:15:20 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/15 11:51:21 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	dlst_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return (FALSE);
	stack->start = stack->start->next;
	return (TRUE);
}

void	op_rotate(t_push_swap *data, char stack_id)
{
	if (stack_id == 'a' && dlst_rotate(data->stack_a))
	{
		data->ops.ra++;
		data->ops.total++;
		ft_printf(1, "ra\n");
		return ;
	}
	if (stack_id == 'b' && dlst_rotate(data->stack_b))
	{
		data->ops.rb++;
		data->ops.total++;
		ft_printf(1, "rb\n");
		return ;
	}
	if (stack_id != 'a' && stack_id != 'b'
		&& (dlst_rotate(data->stack_a) | dlst_rotate(data->stack_b)))
	{
		data->ops.rr++;
		data->ops.total++;
		ft_printf(1, "rr\n");
	}
}

static t_bool	dlst_reverse_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return (FALSE);
	stack->start = stack->start->prev;
	return (TRUE);
}

void	op_rotate_reverse(t_push_swap *data, char stack_id)
{
	if (stack_id == 'a' && dlst_reverse_rotate(data->stack_a))
	{
		data->ops.rra++;
		data->ops.total++;
		ft_printf(1, "rra\n");
		return ;
	}
	if (stack_id == 'b' && dlst_reverse_rotate(data->stack_b))
	{
		data->ops.rrb++;
		data->ops.total++;
		ft_printf(1, "rrb\n");
		return ;
	}
	if (stack_id != 'a' && stack_id != 'b'
		&& (dlst_reverse_rotate(data->stack_a)
			| dlst_reverse_rotate(data->stack_b)))
	{
		data->ops.rrr++;
		data->ops.total++;
		ft_printf(1, "rrr\n");
	}
}
