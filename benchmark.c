/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 00:00:00 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/08/03 11:40:47 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_strategy(t_strategy strategy, double disorder)
{
	if (strategy == STRAT_SIMPLE)
		ft_printf(2, "[bench] strategy:  simple / O(n^2)\n");
	else if (strategy == STRAT_MEDIUM)
		ft_printf(2, "[bench] strategy:  medium / O(n*sqrt(n))\n");
	else if (strategy == STRAT_COMPLEX)
		ft_printf(2, "[bench] strategy:  complex / O(n log n)\n");
	else
	{
		if (disorder < 0.2)
			ft_printf(2, "[bench] strategy:  Adaptive / O(n^2)\n");
		else if (disorder < 0.5)
			ft_printf(2, "[bench] strategy:  Adaptive / O(n*sqrt(n))\n");
		else
			ft_printf(2, "[bench] strategy:  Adaptive / O(n log n)\n");
	}
}

static void	print_operation_counts(t_op_count *ops)
{
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d", ops->sa,
		ops->sb, ops->ss);
	ft_printf(2, " pa: %d pb: %d\n", ops->pa, ops->pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d", ops->ra, ops->rb, ops->rr);
	ft_printf(2, " rra: %d rrb: %d rrr: %d\n", ops->rra, ops->rrb, ops->rrr);
}

void	print_benchmark(t_push_swap *data, double disorder)
{
	if (data->bench == FALSE)
		return ;
	print_disorder(disorder);
	print_strategy(data->strategy, disorder);
	ft_printf(2, "[bench] total_ops:  %d\n", data->ops.total);
	print_operation_counts(&data->ops);
}
