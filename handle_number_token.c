/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 14:38:17 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/08 10:58:02 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	handle_number_token(char *token, t_push_swap *data)
{
	t_stack	*stack_a;
	t_list	*node;
	int		content;

	stack_a = data->stack_a;
	content = ft_atoi(token);
	node = ft_lstnew((void *)(long)content);
	stack_a->last = node;
	ft_lstadd_back(&stack_a->start, node);
	stack_a->len++;
	return (TRUE);
}
