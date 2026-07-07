/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:53:25 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/07 14:23:30 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	parse_flag(int argc, char **argv, t_push_swap *data)
{
	int	i;

	i = 1;
	ft_printf("%i \n", argc);
	if (!data)
		return (FALSE);
	while (argv[i])
	{
		// if(is_strategy_flag(argv[i]))
			// nem ideia :D
		if (is_valid_int(argv[i])) 
			ft_printf("int valido: %s\n", argv[i]);
		else
			return (FALSE);
		i++;
	}
	return (TRUE);
}
