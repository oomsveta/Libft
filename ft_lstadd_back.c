/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:14:31 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 17:37:05 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides provides ft_lstlast, t_list

void	ft_lstadd_back(t_list **head, t_list *node)
{
	if (!*head)
	{
		*head = node;
		return ;
	}
	ft_lstlast(*head)->next = node;
}
