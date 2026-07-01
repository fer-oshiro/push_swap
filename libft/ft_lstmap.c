/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:35:38 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/05/29 14:15:21 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_clear(t_list **lst, void (*del)(void *), void *content)
{
	if (content)
		del(content);
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_head = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			return (ft_clear(&new_head, del, content));
		new = ft_lstnew(content);
		if (!new)
			return (ft_clear(&new_head, del, content));
		ft_lstadd_back(&new_head, new);
		lst = lst->next;
	}
	return (new_head);
}
