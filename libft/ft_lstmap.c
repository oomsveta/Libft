/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:02:05 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 00:22:46 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides ft_lstclear, ft_lstnew, NULL, t_list

t_list *ft_lstmap(t_list *lst, void *(*fn)(void *), void (*delete_fn)(void *))
{
	t_list	*mapped;
	t_list	*new_node;
	t_list	**tail;
	void	*new_content;

	mapped = NULL;
	tail = &mapped;
	while (lst)
	{
		new_content = fn(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			delete_fn(new_content);
			ft_lstclear(&mapped, delete_fn);
			return (NULL);
		}
		*tail = new_node;
		tail = &new_node->next;
		lst = lst->next;
	}
	return (mapped);
}
