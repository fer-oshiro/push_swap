/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:40:46 by aschulz-          #+#    #+#             */
/*   Updated: 2026/07/09 16:19:38 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double compute_disorder(t_push_swap *data)
{
	int mistakes;
	int	total_pairs;
	 *i;
	int j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while(i < data->total - 1)
	{
		j = i + 1;
		while(j < data->total)
		{
			total_pairs++;
			if (data->stack_a->content-> data->stack_a->len)
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes/ total_pairs);
}
