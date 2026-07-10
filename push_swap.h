/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:29:04 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/10 11:14:15 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_node
{
    int             content;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct s_stack
{
	t_node	*start;
	int		size;
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
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_strategy	strategy;
	t_bool		bench;
	int			size;
}	t_push_swap;

void	handle_initialization_data(t_push_swap	*data);
void	handle_free_data(t_push_swap *data);
t_bool	parse_flag(char **argv, t_push_swap *data);
t_bool	is_valid_int(char *token, t_push_swap *data);
t_bool	is_strategy_flag(char *tokien, t_push_swap *data);
long	ft_atol(char *token);
t_bool	handle_number_token(char *token, t_push_swap *data);
char	**ft_split_whitespace(char *token);
void	ft_free_split(char **res);
void	sort_strategy(char *token, t_push_swap *data);
t_node *dlst_create_node(int content);
void	dlst_add_back(t_node **start, t_node *new);
void	dlst_iter(t_stack stack, void (*f)(int));
void	dlst_add_front(t_node **start, t_node *new);
double	compute_disorder(t_push_swap *data);

#endif