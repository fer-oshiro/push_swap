/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_indexes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staut <staut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:30:05 by staut             #+#    #+#             */
/*   Updated: 2026/07/18 02:08:24 by staut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    set_stack_indexes(t_stack *stack)
{
    int i;
    int j;
    int count;
    t_node *curr;
    t_node *runner;

    i = 0;
    curr = stack->start;
    while (i < stack->size)
    {
        count = 0;
        runner = stack->start;
        j = 0;
        while (j < stack->size)
        {
            if (runner->content < curr->content)
            count++;
            runner = runner->next;
            j++;
        }
        curr->index = count;
        printf("val: %d\n index: %d\n", curr->content, curr->index);
        curr = curr->next;
        i++;
    } 
}
