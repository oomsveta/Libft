/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:21:13 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/07 18:23:36 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides free
#include "libft.h"	// provides t_list

void	ft_lstdelone(t_list *node, void (*delete_fn)(void *))
{
	if (!node)
	{
		return ;
	}
	delete_fn(node->content);
	free(node);
}
