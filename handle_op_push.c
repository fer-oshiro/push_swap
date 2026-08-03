/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 10:15:16 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/08/03 13:43:02 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_push_swap *data)
{
	t_node	*node;

	node = dlst_remove_front(data->stack_b);
	if (node == NULL)
		return ;
	dlst_add_front(data->stack_a, node);
	data->ops.pa++;
	data->ops.total++;
	if (data->bench == FALSE)
		ft_printf(1, "pa\n");
}

void	op_pb(t_push_swap *data)
{
	t_node	*node;

	node = dlst_remove_front(data->stack_a);
	if (node == NULL)
		return ;
	dlst_add_front(data->stack_b, node);
	data->ops.pb++;
	data->ops.total++;
	if (data->bench == FALSE)
		ft_printf(1, "pb\n");
}
