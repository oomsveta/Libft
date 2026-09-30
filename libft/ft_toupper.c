/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:54:04 by lwicket           #+#    #+#             */
/*   Updated: 2026/09/30 17:42:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	ft_islower(int c)
{
	return ((unsigned int)c - 'a' < 26U);
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
	{
		return (c ^ 0x20);
	}
	return (c);
}
