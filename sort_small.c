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

static void	sort_three(t_push_swap *data)
{
	int	first;
	int	second;
	int	third;

	first = data->stack_a->start->content;
	second = data->stack_a->start->next->content;
	third = data->stack_a->start->prev->content;
	if (first > second && first < third)
		op_sa(data);
	else if (first > second && second > third)
	{
		op_sa(data);
		op_rra(data);
	}
	else if (first > second && first > third)
		op_ra(data);
	else if (first < second && first < third)
	{
		op_sa(data);
		op_ra(data);
	}
	else
		op_rra(data);
}

void	sort_small(t_push_swap *data)
{
	if (!data || !data->stack_a || data->stack_a->size < 2)
		return ;
	if (data->stack_a->size == 2)
	{
		if (data->stack_a->start->content
			> data->stack_a->start->next->content)
			op_sa(data);
		return ;
	}
	if (data->stack_a->size == 3)
		sort_three(data);
}
