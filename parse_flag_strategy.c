/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag_strategy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:24:32 by aschulz-          #+#    #+#             */
/*   Updated: 2026/07/08 15:31:56 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool is_strategy_flag(char *token, t_push_swap *data)
{
	if (ft_strncmp(token, "--bench", 8) == 0 && data->bench == TRUE)
		return (FALSE);
	if((ft_strncmp(token, "--bench", 8) == 0))
		return (TRUE);
	if(data->strategy != STRAT_EMPTY)
		return (FALSE);
	if((ft_strncmp(token, "--simple", 9) == 0))
		return (TRUE);
	if((ft_strncmp(token, "--medium", 9) == 0))
		return (TRUE);
	if((ft_strncmp(token, "--complex", 10) == 0))
		return (TRUE);
	if((ft_strncmp(token, "--adaptive", 11) == 0))
		return (TRUE);
	return (FALSE);
}
