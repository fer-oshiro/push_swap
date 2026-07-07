/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:29:04 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/07 16:45:46 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_node
{
	int		content;
	t_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*start;
	t_node	*last;
	int		len;
}	t_stack;

typedef enum s_strategy
{
	STRAT_EMPTY,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
	STRAT_ADAPTIVE
}	t_strategy;

typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_strategy strategy;
	t_bool	bench;
	int		total;
} t_push_swap;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;


#endif