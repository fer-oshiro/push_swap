/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:40:46 by aschulz-          #+#    #+#             */
/*   Updated: 2026/07/10 11:07:01 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double compute_disorder(t_push_swap *data)
{
	int 	mistakes;
	t_node	*current;
	t_node	*runner;
	int		i;
	int		j;

	mistakes = 0;
	i = 0;
	current = data->stack_a->size;
	while(i < data->stack_a->size - 1)
	{
		j = i + 1;
		runner = current->next;
		while(j < data->stack_a->size)
		{
			total_pairs++;
			if (current->content > runner->content)
				mistakes++;
			runner = runner->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes/ total_pairs);
}

