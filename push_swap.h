/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staut <staut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:29:04 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/31 11:41:44 by staut            ###   ########.fr       */
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
	int				content;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

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

typedef struct s_op_count
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_op_count;

typedef struct s_push_swap
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_strategy	strategy;
	t_bool		bench;
	int			size;
	t_op_count	ops;
}	t_push_swap;

void	init_data(t_push_swap *data);
void	free_data(t_push_swap *data);
t_bool	parse_flag(char **argv, t_push_swap *data);
t_bool	is_valid_int(char *token, t_push_swap *data);
t_bool	is_strategy_flag(char *tokien, t_push_swap *data);
long	ft_atol(char *token);
t_bool	handle_number_token(char *token, t_push_swap *data);
char	**ft_split_whitespace(char *token);
void	ft_free_split(char **res);
void	sort_strategy(char *token, t_push_swap *data);

t_node	*dlst_create_node(int content);
void	dlst_add_front(t_stack *start, t_node *new);
void	dlst_add_back(t_stack *stack, t_node *new);
void	dlst_iter(t_stack stack, void (*f)(int));
t_node	*dlst_remove_front(t_stack *stack);
t_node	*stack_min(t_stack *stack);
t_node	*stack_max(t_stack *stack);
int		stack_position(t_stack *stack, t_node *target);
int		rotation_cost(t_stack *stack, t_node *target);

double	compute_disorder(t_push_swap *data);
void	print_disorder(double disorder);
void	print_benchmark(t_push_swap *data, double disorder);
void	set_stack_indexes(t_stack *stack);
void	sort_small(t_push_swap *data);
void	sort_medium(t_push_swap *data);
void	select_algorithm(t_push_swap *data);
static void	sort_three(t_push_swap *data);

void	op_pa(t_push_swap *data);
void	op_pb(t_push_swap *data);
void	op_sa(t_push_swap *data);
void	op_sb(t_push_swap *data);
void	op_ss(t_push_swap *data);
void	op_ra(t_push_swap *data);
void	op_rb(t_push_swap *data);
void	op_rr(t_push_swap *data);
void	op_rra(t_push_swap *data);
void	op_rrb(t_push_swap *data);
void	op_rrr(t_push_swap *data);

void	sort_complex(t_push_swap *data);
void	sort_simple(t_push_swap *data);

#endif
