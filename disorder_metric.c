/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staut <staut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:40:46 by aschulz-          #+#    #+#             */
/*   Updated: 2026/07/17 10:03:14 by staut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float   compute_disorder(t_push_swap *data)
{
    int     mistakes;
    t_node  *i_node;
    t_node  *j_node;
    int     i;

    mistakes = 0;
    i = 0;
    i_node = data->stack_a->start;
    while (i < data->stack_a->size)
    {
        j_node = i_node->next;
        while (j_node != NULL && j_node != data->stack_a->start)
        {
            if (i_node->content > j_node->content)
                mistakes++;
            j_node = j_node->next;
        }
        i_node = i_node->next;
        i++;
    }
    if (data->stack_a->size <= 1)
        return (0.0);
    return ((float)mistakes / ((data->stack_a->size * (data->stack_a->size - 1)) / 2));
}

void	print_disorder(float disorder)
{
	int		whole;
	int		decimal;
	double	percent;

	if (disorder < 0)
		disorder = 0;
	percent = disorder * 100;
	whole = (int)percent;
	decimal = (int)((percent - whole) * 100 + 0.5);
	if (decimal >= 100)
	{
		whole++;
		decimal = 0;
	}
	ft_printf(2, "[bench] disorder:  %d.", whole);
	if (decimal < 10)
		ft_printf(2, "0");
	ft_printf(2, "%d%%\n", decimal);
}
