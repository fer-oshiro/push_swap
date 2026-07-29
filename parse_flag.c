/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:53:25 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/10 10:20:11 by fsayuri-         ###   ########.fr       */
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

static t_bool	parse_argument(char *argument, t_push_swap *data)
{
	int		j;
	char	**res;

	j = 0;
	res = ft_split_whitespace(argument);
	if (!res || !res[0])
	{
		free(res);
		return (FALSE);
	}
	while (res[j])
	{
		if (!validate_and_store_token(res[j], data))
		{
			ft_free_split(res);
			return (FALSE);
		}
		j++;
	}
	ft_free_split(res);
	return (TRUE);
}

t_bool	parse_flag(char **argv, t_push_swap *data)
{
	int	i;

	i = 1;
	if (!data)
		return (FALSE);
	while (argv[i])
	{
		if (!parse_argument(argv[i], data))
			return (FALSE);
		i++;
	}
	if (data->stack_a->size == 0)
		return (FALSE);
	data->size = data->stack_a->size;
	return (TRUE);
}
