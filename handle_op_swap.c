/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:49:48 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/15 11:50:27 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	dlst_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp_value;
	int		temp_index;

	if (!stack || stack->size < 2)
		return (FALSE);
	first = stack->start;
	second = first->next;
	temp_value = first->content;
	first->content = second->content;
	second->content = temp_value;
	temp_index = first->index;
	first->index = second->index;
	second->index = temp_index;
	return (TRUE);
}

void	op_swap(t_push_swap *data, char stack_id)
{
	if (stack_id == 'a' && dlst_swap(data->stack_a))
	{
		data->ops.sa++;
		data->ops.total++;
		ft_printf(1, "sa\n");
		return ;
	}
	if (stack_id == 'b' && dlst_swap(data->stack_b))
	{
		data->ops.sb++;
		data->ops.total++;
		ft_printf(1, "sb\n");
		return ;
	}
	if (stack_id != 'a' && stack_id != 'b'
		&& (dlst_swap(data->stack_a) | dlst_swap(data->stack_b)))
	{
		data->ops.ss++;
		data->ops.total++;
		ft_printf(1, "ss\n");
	}
}
