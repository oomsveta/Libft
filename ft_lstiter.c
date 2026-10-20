/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:29:46 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 17:38:08 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides t_list

void	ft_lstiter(t_list *lst, void (*fn)(void *))
{
	while (lst)
	{
		fn(lst->content);
		lst = lst->next;
	}
}
