/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 00:00:00 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/28 00:00:00 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_strategy(t_strategy strategy)
{
	if (strategy == STRAT_SIMPLE)
		ft_printf(2, "[bench] strategy:  simple (O(n^2))\n");
	else if (strategy == STRAT_MEDIUM)
		ft_printf(2, "[bench] strategy:  medium (O(n*sqrt(n)))\n");
	else if (strategy == STRAT_COMPLEX)
		ft_printf(2, "[bench] strategy:  complex (O(n log n))\n");
	else
		ft_printf(2, "[bench] strategy:  adaptive (variable)\n");
}

static void	print_operation_counts(t_op_count *ops)
{
	ft_printf(2, "[bench] operations: sa=%d sb=%d ss=%d", ops->sa,
		ops->sb, ops->ss);
	ft_printf(2, " pa=%d pb=%d", ops->pa, ops->pb);
	ft_printf(2, " ra=%d rb=%d rr=%d", ops->ra, ops->rb, ops->rr);
	ft_printf(2, " rra=%d rrb=%d rrr=%d\n", ops->rra, ops->rrb, ops->rrr);
}

void	print_benchmark(t_push_swap *data, double disorder)
{
	if (data->bench == FALSE)
		return ;
	print_disorder(disorder);
	print_strategy(data->strategy);
	ft_printf(2, "[bench] total operations:  %d\n", data->ops.total);
	print_operation_counts(&data->ops);
}
