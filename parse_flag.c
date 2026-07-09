/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:53:25 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/09 17:35:58 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_bool	validate_and_store_token(char *token, t_push_swap *data)
{
	if (is_strategy_flag(token, data))
		sort_strategy(token, data);
	else if (is_valid_int(token, data))
		handle_number_token(token, data);
	else
		return (FALSE);
	return (TRUE);
}

t_bool	parse_flag(char **argv, t_push_swap *data)
{
	int		i;
	int		j;
	char	**res;

	i = 1;
	if (!data)
		return (FALSE);
	while (argv[i])
	{
		j = 0;
		res = ft_split_whitespace(argv[i]);
		while (res[j])
		{
			if (!validate_and_store_token(res[j], data))
			{
				ft_free_split(res);
				return (FALSE);
			}
			j++;
		}
		i++;
		ft_free_split(res);
	}
	return (TRUE);
}
