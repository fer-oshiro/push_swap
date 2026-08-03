/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:49:48 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/08/03 13:44:14 by aschulz-         ###   ########.fr       */
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

void	op_sa(t_push_swap *data)
{
	if (!dlst_swap(data->stack_a))
		return ;
	data->ops.sa++;
	data->ops.total++;
	if (data->bench == FALSE)
		ft_printf(1, "sa\n");
}

void	op_sb(t_push_swap *data)
{
	if (!dlst_swap(data->stack_b))
		return ;
	data->ops.sb++;
	data->ops.total++;
	if (data->bench == FALSE)
		ft_printf(1, "sb\n");
}

void	op_ss(t_push_swap *data)
{
	t_bool	swapped_a;
	t_bool	swapped_b;

	swapped_a = dlst_swap(data->stack_a);
	swapped_b = dlst_swap(data->stack_b);
	if (!swapped_a && !swapped_b)
		return ;
	data->ops.ss++;
	data->ops.total++;
	if (data->bench == FALSE)
		ft_printf(1, "ss\n");
}
