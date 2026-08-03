/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 11:31:05 by staut             #+#    #+#             */
/*   Updated: 2026/08/03 10:45:43 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_handle_small_stacks(t_push_swap *data);

void	select_algorithm(t_push_swap *data)
{
	double	disorder;

	if (data->stack_a->size <= 5)
	{
		ft_handle_small_stacks(data);
		return ;
	}
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
		else if (disorder < 0.5)
			sort_medium(data);
		else
			sort_complex(data);
	}
}

void	ft_handle_small_stacks(t_push_swap *data)
{
	int	len;

	len = data->stack_a->size;
	if (len == 2)
		sort_2(data);
	else if (len == 3)
		sort_3(data);
	else if (len == 4)
		sort_4(data);
	else if (len == 5)
		sort_5(data);
}
