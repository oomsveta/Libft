/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:24:16 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 19:54:06 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides ft_lstdelone, t_list

void	ft_lstclear(t_list **head, void (*delete_fn)(void *))
{
	t_list	*current;

	while (*head)
	{
		current = *head;
		*head = current->next;
		ft_lstdelone(current, delete_fn);
	}
}
