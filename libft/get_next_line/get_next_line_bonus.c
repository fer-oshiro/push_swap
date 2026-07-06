/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:48:11 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/06/18 14:32:37 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	get_res(int fd, char **res)
{
	int	bytes_read;

	if (*res)
		return ;
	*res = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!*res)
		return ;
	bytes_read = read(fd, *res, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(*res);
		*res = NULL;
	}
}

static void	get_content(int fd, char **res)
{
	char	*buff;
	char	*temp;
	int		bytes_read;

	while (ft_strchr(*res, '\n') == 0)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buff);
			break ;
		}
		temp = ft_strjoin(*res, buff);
		free(*res);
		*res = temp;
		free(buff);
	}
}

static void	separate_res_and_result(char **res, char **result)
{
	int		len;
	char	*temp;

	temp = *res;
	if (!temp || *temp == '\0')
	{
		free(*res);
		*res = NULL;
		return ;
	}
	len = 0;
	while (temp[len] != '\n' && temp[len] != '\0')
		len++;
	*result = ft_substr(temp, 0, len + 1);
	if (temp[len] == '\n' && temp[len + 1] != '\0')
		*res = ft_substr(temp, len + 1, BUFFER_SIZE);
	else
		*res = NULL;
	free(temp);
}

char	*get_next_line(int fd)
{
	static char	*res[4096];
	char		*result;

	if (fd < 0)
		return (NULL);
	get_res(fd, &res[fd]);
	if (!res[fd])
		return (NULL);
	get_content(fd, &res[fd]);
	separate_res_and_result(&res[fd], &result);
	return (result);
}
