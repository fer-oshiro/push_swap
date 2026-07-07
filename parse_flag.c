/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:53:25 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/07 16:50:03 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	parse_flag(int argc, char **argv, t_push_swap *data)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if(is_strategy_flag(argv[i]) == TRUE)
		{
			sort_strategy(argv[i], data); //SO GUARDA A INFORMAÇÃO;
		}
			//forçar a usar o algoritimo
		// if () 
			// nem ideia 2 :D
		// else
		// 	return (FALSE);
		i++;
	}
	return (TRUE);
}