/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 15:40:46 by aschulz-          #+#    #+#             */
/*   Updated: 2026/07/10 10:02:22 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double compute_disorder(t_push_swap *data)
{
	int 	mistakes;
	int		total_pairs;
	t_node	*current;
	t_node	*runner;

	mistakes = 0;
	total_pairs = 0;
	current = data->stack_a->start;
	while(current != NULL && current->next != NULL)
	{
		runner = current->next; // j = i + 1;
		while(runner != NULL)
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


int main(void)
{
    double disorder = compute_disorder(&data);
    printf("Métrica de desordem: %f\n", disorder);

    t_node *tmp;
    t_node *curr = stack_a.start;


    return (0); 
