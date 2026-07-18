/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 10:12:34 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/15 10:15:08 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*dlst_create_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	dlst_add_back(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	stack->size++;
	if (!stack->start)
	{
		stack->start = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = stack->start->prev;
	last->next = new;
	new->prev = last;
	new->next = stack->start;
	stack->start->prev = new;
}

void	dlst_add_front(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	stack->size++;
	if (!stack->start)
	{
		stack->start = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = stack->start->prev;
	last->next = new;
	new->prev = last;
	new->next = stack->start;
	stack->start->prev = new;
	stack->start = new;
}

t_node	*dlst_remove_front(t_stack *stack)
{
	t_node	*removed;
	t_node	*last;

	if (!stack || !stack->start)
		return (NULL);
	removed = stack->start;
	stack->size--;
	if (stack->size == 0)
		stack->start = NULL;
	else
	{
		last = removed->prev;
		stack->start = removed->next;
		last->next = stack->start;
		stack->start->prev = last;
	}
	removed->next = NULL;
	removed->prev = NULL;
	return (removed);
}

void	dlst_iter(t_stack stack, void (*f)(int))
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack.start;
	if (f == NULL)
		return ;
	while (i < stack.size)
	{
		f(node->content);
		node = node->next;
		i++;
	}
}
