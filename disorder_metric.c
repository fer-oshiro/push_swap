/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:40:46 by aschulz-          #+#    #+#             */
/*   Updated: 2026/07/10 12:05:48 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double compute_disorder(t_push_swap *data)
{
	int 	mistakes;
	int 	total_pairs;
	t_node	*i_node;
	t_node	*j_node;
	int		i;
	int		j;

	total_pairs = 0;
	mistakes = 0;
	i = 0;
	i_node = data->stack_a->start;
	while(i < data->stack_a->size)
	{
		j = i + 1;
		j_node = i_node->next;
		while(j < data->stack_a->size)
		{
			if (i_node->content > j_node->content)
				mistakes++;
			total_pairs++;
			j_node = j_node->next;
			j++;
		}
		i_node = i_node->next;
		i++;
	}
	return ((double)mistakes / total_pairs);
	
}

