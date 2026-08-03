/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 10:15:20 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/08/03 13:43:46 by aschulz-         ###   ########.fr       */
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

void	op_ra(t_push_swap *data)
{
	if (!dlst_rotate(data->stack_a))
		return ;
	data->ops.ra++;
	data->ops.total++;
	if (data->bench == FALSE)
		ft_printf(1, "ra\n");
}

void	op_rb(t_push_swap *data)
{
	if (!dlst_rotate(data->stack_b))
		return ;
	data->ops.rb++;
	data->ops.total++;
	if (data->bench == FALSE)
		ft_printf(1, "rb\n");
}

void	op_rr(t_push_swap *data)
{
	t_bool	rotated_a;
	t_bool	rotated_b;

	rotated_a = dlst_rotate(data->stack_a);
	rotated_b = dlst_rotate(data->stack_b);
	if (!rotated_a && !rotated_b)
		return ;
	data->ops.rr++;
	data->ops.total++;
	if (data->bench == FALSE)
		ft_printf(1, "rr\n");
}
