/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_min(t_stack *stack)
{
	t_node	*node;
	t_node	*min;
	int		i;

	if (!stack || !stack->start || stack->size <= 0)
		return (NULL);
	node = stack->start;
	min = node;
	i = 0;
	while (i < stack->size)
	{
		if (node->index < min->index)
			min = node;
		node = node->next;
		i++;
	}
	return (min);
}

t_node	*stack_max(t_stack *stack)
{
	t_node	*node;
	t_node	*max;
	int		i;

	if (!stack || !stack->start || stack->size <= 0)
		return (NULL);
	node = stack->start;
	max = node;
	i = 0;
	while (i < stack->size)
	{
		if (node->index > max->index)
			max = node;
		node = node->next;
		i++;
	}
	return (max);
}

int	stack_position(t_stack *stack, t_node *target)
{
	t_node	*node;
	int		position;

	if (!stack || !stack->start || !target || stack->size <= 0)
		return (-1);
	node = stack->start;
	position = 0;
	while (position < stack->size)
	{
		if (node == target)
			return (position);
		node = node->next;
		position++;
	}
	return (-1);
}

int	rotation_cost(t_stack *stack, t_node *target)
{
	int	position;

	if (!stack || !stack->start || !target || stack->size <= 0)
		return (0);
	position = stack_position(stack, target);
	if (position < 0)
		return (0);
	if (position <= stack->size / 2)
		return (position);
	return (position - stack->size);
}
