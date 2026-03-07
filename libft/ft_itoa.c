/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:06:40 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/02 09:30:39 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>	// provides CHAR_BIT
#include "libft.h"	// provides ft_strdup

unsigned int	ft_abs(int n)
{
	if (n < 0)
	{
		return (-(unsigned int)n);
	}
	return (+n);
}

char	*ft_itoa(int n)
{
	char			buffer[(sizeof(int) * CHAR_BIT - 1) * 28 / 93 + 3];
	char			*nptr;
	unsigned int	acc;

	nptr = buffer + sizeof buffer;
	*--nptr = '\0';
	acc = ft_abs(n);
	while (acc >= 10)
	{
		*--nptr = acc % 10 | '0';
		acc /= 10;
	}
	*--nptr = acc % 10 | '0';
	if (n < 0)
	{
		*--nptr = '-';
	}
	return (ft_strdup(nptr));
}
