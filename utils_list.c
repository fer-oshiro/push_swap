/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:10:00 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/10 10:09:21 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *dlst_create_node(int content)
{
	t_node *node;
	
	node = malloc(sizeof(t_node));
	if (!node)
		return(NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return(node);
}

void	dlst_add_back(t_node **start, t_node *new)
{
	t_node	*last;

	if (!new)
		return ;
	if (!*start)
	{
		*start = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*start)->prev;
	last->next = new;
	new->prev = last;
	new->next = *start;
	(*start)->prev = new;
}

void dlst_iter(t_stack stack, void (*f)(int))
{
	t_node *node;
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