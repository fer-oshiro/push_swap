/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:29:04 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/07 12:43:50 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	int		content;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*start;
	t_node	*last;
	int		len;
}	t_stack;

typedef struct s_seila
{
	/* data */
}	t_seila;


typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		total;
	// ....
} t_push_swap;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

t_bool	parse_flag(int argc, char **argv, t_push_swap *data);
t_bool	is_valid_int(char *token);
long	ft_atol(char *token);

#endif