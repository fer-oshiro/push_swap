/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 14:45:55 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/07 15:32:25 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_initialization_data(t_push_swap	*data)
{
	data->stack_a = malloc(sizeof(t_stack));
    data->stack_b = malloc(sizeof(t_stack));
	if (!data->stack_a || !data->stack_b)
        return ;
	data->stack_a->start = NULL;
    data->stack_a->last = NULL;
    data->stack_a->len = 0;
    data->stack_b->start = NULL;
    data->stack_b->last = NULL;
    data->stack_b->len = 0;
    data->total = 0;
}
