/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_swaps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:11:00 by aschulz-          #+#    #+#             */
/*   Updated: 2026/07/10 10:11:11 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void operator_sa(t_stack *stack, t_push_swap *data)
{
    t_node  *first;
    t_node  *second;
    int     temp_content;
    int     temp_index;

    // Regra obrigatória: verifica se há pelo menos 2 elementos [3]
    if (!stack || stack->len < 2)
        return ;

    // Aponta para os nós reais que estão no topo da pilha
    first = stack->start;
    second = first->next;

    // Troca o conteúdo (content) [4]
    temp_content = first->content;
    first->content = second->content;
    second->content = temp_content;

    // Se você usa o índice para ordenação, também deve trocá-lo
    temp_index = first->index;
    first->index = second->index;
    second->index = temp_index;

    // Atualiza o contador total e imprime a operação [5, 6]
    data->total++;
    write(1, "sa\n", 3);
}

// Função genérica que faz a troca física (lógica interna)
static void	generic_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	// Regra obrigatória: não faz nada se houver menos de 2 elementos [1]
	if (!stack || stack->len < 2)
		return ;
	first = stack->start;
	second = first->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
	// Se usar índice para o algoritmo adaptativo, troque-o também
}

void	operator_sa(t_push_swap *data)
{
	generic_swap(data->stack_a);
	// Diferenciação:
	data->total++; // Contador total para o benchmark [2]
	// Se você tiver uma estrutura bench separada dentro de data:
	// data->bench.sa++; 
	write(1, "sa\n", 3); // Nome da operação exigido [4]
}

void	operator_sb(t_push_swap *data)
{
	generic_swap(data->stack_b);
	// Diferenciação:
	data->total++;
	// data->bench.sb++;
	write(1, "sb\n", 3);
}