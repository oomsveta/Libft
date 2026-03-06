/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:14:43 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/01 21:42:24 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	byte_by_byte_copy(
	unsigned char *dest, const unsigned char *src, size_t n
)
{
	while (n--)
	{
		*dest++ = *src++;
	}
}

/**
 * If the __may_alias__ attribute is available (to bypass strict aliasing) and
 * the architecture allows unaligned access, use the high-performance version.
 */
#if defined(__GNUC__) && \
	(defined(__x86_64__) || defined(__i386__) || defined(__aarch64__))

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const size_t		align = -(uintptr_t)dest & (sizeof(uintptr_t) - 1);
	unsigned char		*d;
	const unsigned char	*s = src;

	d = dest;
	if (n < sizeof(uintptr_t))
	{
		byte_by_byte_copy(dest, src, n);
		return (dest);
	}
	*(t_uintptr_alias *)d = *(t_uintptr_alias *)s;
	*(t_uintptr_alias *)(d + n - sizeof(uintptr_t))
		= *(t_uintptr_alias *)(s + n - sizeof(uintptr_t));
	d += align;
	s += align;
	n -= align;
	while (n >= sizeof(uintptr_t))
	{
		*(t_uintptr_alias *)d = *(t_uintptr_alias *)s;
		d += sizeof(uintptr_t);
		s += sizeof(uintptr_t);
		n -= sizeof(uintptr_t);
	}
	return (dest);
}

#else

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	byte_by_byte_copy(dest, src, n);
	return (dest);
}

#endif
