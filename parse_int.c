/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:11:14 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/07/08 15:43:26 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

t_bool	is_only_number(char *token)
{
	int	i;

	i = 0;
	if (token[0] == '-' || token[0] == '+')
		i = 1;
	if (token[i] == '\0')
		return (FALSE);
	while (token[i])
	{
		if (token[i] < '0' || token[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	validation_duplicated(t_list *lst, long content)
{
	while (lst)
	{
		if ((void *)(long)content == (void *)(long)lst->content)
			return (FALSE);
		lst = lst->next;
	}
	return (TRUE);
}

t_bool	is_valid_int(char *token, t_push_swap *data)
{
	size_t	len;
	long	num;

	if (!token || token[0] == '\0')
		return (FALSE);
	len = ft_strlen(token);
	if (len > 11)
		return (FALSE);
	if (len == 11 && (token[0] != '-' && token[0] != '+'))
		return (FALSE);
	if (!is_only_number(token))
		return (FALSE);
	num = ft_atol(token);
	if (num < -2147483648 || num > 2147483647)
		return (FALSE);
	return (validation_duplicated(data->stack_a->start, num));
}
