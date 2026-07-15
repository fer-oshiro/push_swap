/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 10:15:20 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/15 11:27:22 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	dlst_rotate(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return ;
    stack->start = stack->start->next;
}

void	op_rotate(t_push_swap *data, char rotate_type)
{
	if (rotate_type == 'a')
	{
		dlst_rotate(data->stack_a);
		ft_printf(1, "ra");
		return;
	}
	if (rotate_type == 'b')
	{
		dlst_rotate(data->stack_b);
		ft_printf(1, "rb");
		return;
	}
	dlst_rotate(data->stack_a);
	dlst_rotate(data->stack_b);
	ft_printf(1, "rr");
}

static void    dlst_reverse_rotate(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return ;
    stack->start = stack->start->prev;
}

void	op_rotate_reverse(t_push_swap *data, char rotate_type)
{
	if (rotate_type == 'a')
	{
		dlst_reverse_rotate(data->stack_a);
		ft_printf(1, "rra");
		return;
	}
	if (rotate_type == 'b')
	{
		dlst_reverse_rotate(data->stack_b);
		ft_printf(1, "rrb");
		return;
	}
	dlst_reverse_rotate(data->stack_a);
	dlst_reverse_rotate(data->stack_b);
	ft_printf(1, "rrr");
}
