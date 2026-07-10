/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:40:46 by aschulz-          #+#    #+#             */
/*   Updated: 2026/07/10 17:19:11 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	total_pairs(t_push_swap *data)
{
	return (data->stack_a->size * (data->stack_a->size - 1) / 2);
}

double	compute_disorder(t_push_swap *data)
{
	int		mistakes;
	t_node	*i_node;
	t_node	*j_node;
	int		i;
	int		j;

	if (data->stack_a->size <= 1)
		return (0.0);
	mistakes = 0;
	i = 0;
	i_node = data->stack_a->start;
	while (i < data->stack_a->size)
	{
		j = i + 1;
		j_node = i_node->next;
		while (j++ < data->stack_a->size)
		{
			if (i_node->content > j_node->content)
				mistakes++;
			j_node = j_node->next;
		}
		i_node = i_node->next;
		i++;
	}
	return ((double)mistakes / ((double)total_pairs(data)));
}
