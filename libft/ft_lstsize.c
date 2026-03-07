/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:09:08 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/07 18:14:59 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides NULL, size_t, t_list

int	ft_lstsize(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst != NULL)
	{
		len += 1;
		lst = lst->next;
	}
	return ((int)len);
}
