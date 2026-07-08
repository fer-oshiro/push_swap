/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 14:51:58 by aschulz-          #+#    #+#             */
/*   Updated: 2026/07/08 13:21:56 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_strategy(char *token, t_push_swap *data)
{
	if((ft_strncmp(token, "--simple", 9) == 0))
		data->strategy = STRAT_SIMPLE;
	if((ft_strncmp(token, "--medium", 9) == 0))
		data->strategy = STRAT_MEDIUM;
	if((ft_strncmp(token, "--complex", 10) == 0))
		data->strategy = STRAT_COMPLEX;
	if((ft_strncmp(token, "--adaptive", 11) == 0))
		data->strategy = STRAT_ADAPTIVE;
	if((ft_strncmp(token, "--bench", 8) == 0))
		data->bench = TRUE;
}
