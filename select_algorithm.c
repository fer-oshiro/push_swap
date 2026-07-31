/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staut <staut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 11:31:05 by staut             #+#    #+#             */
/*   Updated: 2026/07/31 11:35:21 by staut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_algorithm(t_push_swap *data)
{
	double	disorder;

	if (data->stack_a->size <= 3)
		sort_three(data);
	else if (data->stack_a->size <= 5)
		sort_small(data);
	else if (data->strategy == STRAT_SIMPLE)
		sort_simple(data);
	else if (data->strategy == STRAT_MEDIUM)
		sort_medium(data);
	else if (data->strategy == STRAT_COMPLEX)
		sort_complex(data);
	else
	{
		disorder = compute_disorder(data);
		if (disorder < 0.2)
			sort_simple(data);
		else if (disorder < 0.5) // Limiar para algoritmo MEDIUM [2]
			sort_medium(data);
		else
			sort_complex(data);
	}
}
