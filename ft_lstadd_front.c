/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:07:34 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/07 18:09:21 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides t_list

void	ft_lstadd_front(t_list **head, t_list *node)
{
	node->next = *head;
	*head = node;
}
