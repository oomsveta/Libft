/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 22:42:39 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/01 17:53:42 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If the __may_alias__ attribute is available (to bypass strict aliasing) and
 * the architecture allows unaligned access, use the high-performance version.
 */
#if defined(__GNUC__) && \
	(defined(__x86_64__) || defined(__i386__) || defined(__aarch64__))

void	*ft_memset(void *buffer, int byte, size_t size)
{
	const size_t	align = -(uintptr_t)buffer & (sizeof(uintptr_t) - 1);
	const uintptr_t	filler = (uintptr_t)-1 / 255 * (unsigned char)byte;
	unsigned char	*ptr;

	ptr = buffer;
	if (size >= sizeof(uintptr_t))
	{
		*(t_uintptr_alias *)ptr = filler;
		*(t_uintptr_alias *)(ptr + size - sizeof(uintptr_t)) = filler;
		ptr += align;
		size -= align;
		while (size >= sizeof(uintptr_t))
		{
			*(t_uintptr_alias *)ptr = filler;
			ptr += sizeof(uintptr_t);
			size -= sizeof(uintptr_t);
		}
		return (buffer);
	}
	while (size != 0)
	{
		*ptr++ = (unsigned char)byte;
		size -= 1;
	}
	return (buffer);
}

/**
 * Slow but portable fallback.
 */
#else

void	*ft_memset(void *buffer, int byte, size_t size)
{
	unsigned char	*ptr;

	ptr = buffer;
	while (size != 0)
	{
		*ptr++ = (unsigned char)byte;
		size -= 1;
	}
	return (buffer);
}

#endif
