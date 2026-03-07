/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:22:10 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/02 09:24:47 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides ft_memcpy

static inline void	*copy_descending(
	unsigned char *dest, const unsigned char *src, size_t n
)
{
	while (n != 0)
	{
		dest[n - 1] = src[n - 1];
		n -= 1;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
	{
		return (dest);
	}
	if ((uintptr_t)dest - (uintptr_t)src < n)
	{
		return (copy_descending(dest, src, n));
	}
	return (ft_memcpy(dest, src, n));
}
