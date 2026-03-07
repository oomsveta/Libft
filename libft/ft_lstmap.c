/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:02:05 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 00:14:34 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides ft_lstclear, ft_lstnew, NULL, t_list

t_list *ft_lstmap(t_list *lst, void *(*fn)(void *), void (*delete_fn)(void *))
{
	t_list	*mapped;
	t_list	*new_node;
	t_list	**tail;

	mapped = NULL;
	tail = &mapped;
	while (lst)
	{
		new_node = ft_lstnew(fn(lst->content));
		if (!new_node)
		{
			ft_lstclear(&mapped, delete_fn);
			return (NULL);
		}
		*tail = new_node;
		tail = &new_node->next;
		lst = lst->next;
	}
	return (mapped);
}
