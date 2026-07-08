/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:53:25 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/08 13:47:53 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	parse_flag(int argc, char **argv, t_push_swap *data)
{
	int	i;
	char	**res;

	i = 1;
	if (!data)
		return (FALSE);
	while (argv[i])
	{
		res = ft_split_whitespace(argv[i]);
		if(is_strategy_flag(argv[i]) == TRUE)
			sort_strategy(argv[i], data);
		if (is_valid_int(argv[i], data))
			handle_number_token(argv[i], data);
		else
		{
			ft_free_split(res);
			return (FALSE);
		}
		i++;
		ft_free_split(res);
	}
	return (TRUE);
}
