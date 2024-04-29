/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:52:16 by rcheong           #+#    #+#             */
/*   Updated: 2024/03/04 12:18:09 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstadd_next(t_list **head, t_list *current, t_list *node)
{
	if (!*head)
	{
		*head = node;
		current = *head;
	}
	else
	{
		current->next = node;
		current = current->next;
	}
	return (current);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;
	t_list	*current;

	head = 0;
	current = 0;
	if (f && del)
	{
		while (lst)
		{
			node = ft_lstnew(f(lst->content));
			if (!node)
			{
				ft_lstclear(&head, del);
				return (0);
			}
			current = ft_lstadd_next(&head, current, node);
			lst = lst->next;
		}
	}
	return (head);
}
