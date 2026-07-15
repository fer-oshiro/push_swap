/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 14:38:17 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/15 10:37:40 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	handle_number_token(char *token, t_push_swap *data)
{
	t_stack	*stack_a;
	t_node	*node;
	int		content;

	stack_a = data->stack_a;
	content = ft_atoi(token);
	node = dlst_create_node(content);
	dlst_add_back(stack_a, node);
	return (TRUE);
}
