/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staut <staut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:29:04 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/18 02:36:00 by staut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"

typedef enum e_bool { FALSE, TRUE } t_bool;

typedef struct s_node {
  int content;
  int index;
  struct s_node *next;
  struct s_node *prev;
} t_node;

typedef struct s_stack {
  t_node *start;
  int size;
} t_stack;

typedef enum s_strategy {
  STRAT_EMPTY,
  STRAT_SIMPLE,
  STRAT_MEDIUM,
  STRAT_COMPLEX,
  STRAT_ADAPTIVE
} t_strategy;

typedef struct s_push_swap {
  t_stack *stack_a;
  t_stack *stack_b;
  t_strategy strategy;
  t_bool bench;
  int size;
} t_push_swap;

void handle_initialization_data(t_push_swap *data);
void handle_free_data(t_push_swap *data);
t_bool parse_flag(char **argv, t_push_swap *data);
t_bool is_valid_int(char *token, t_push_swap *data);
t_bool is_strategy_flag(char *tokien, t_push_swap *data);
long ft_atol(char *token);
t_bool handle_number_token(char *token, t_push_swap *data);
char **ft_split_whitespace(char *token);
void ft_free_split(char **res);
void sort_strategy(char *token, t_push_swap *data);

t_node *dlst_create_node(int content);
void dlst_add_front(t_stack *start, t_node *new);
void dlst_add_back(t_stack *stack, t_node *new);
void dlst_iter(t_stack stack, void (*f)(int));
t_node *dlst_remove_front(t_stack *stack);

float	compute_disorder(t_push_swap *data);
void	print_disorder(float disorder);
void	set_stack_indexes(t_stack *stack);
void	select_algorithm(t_push_swap *data);

void op_pa(t_push_swap *data);
void op_pb(t_push_swap *data);
void op_rotate(t_push_swap *data, char rotate_type);
void op_rotate_reverse(t_push_swap *data, char rotate_type);
void op_swap(t_push_swap *data, char rotate_type);

#endif
