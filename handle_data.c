/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 14:45:55 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/15 10:31:37 by fsayuri-         ###   ########.fr       */
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
	data->stack_a->size = 0;
	data->stack_b->start = NULL;
	data->stack_b->size = 0;
	data->size = 0;
	data->strategy = STRAT_EMPTY;
}

static void handle_free_stack(t_stack *stack)
{
    t_node *curr;
    t_node *next;

    if (stack == NULL)
        return ;
    if (stack->start != NULL && stack->size > 0)
    {
        if (stack->start->prev != NULL)
            stack->start->prev->next = NULL;
        curr = stack->start;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = NULL;
            curr->prev = NULL;
            free(curr);
            curr = next;
        }
    }
    free(stack);
}

void handle_free_data(t_push_swap *data)
{
	if (data == NULL)
        return ;
	if (data->stack_a != NULL)
		handle_free_stack(data->stack_a);
	if (data->stack_b != NULL)
		handle_free_stack(data->stack_b);
    data->stack_a = NULL;
    data->stack_b = NULL;
}
