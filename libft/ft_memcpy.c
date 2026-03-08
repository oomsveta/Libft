/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:14:43 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 15:55:31 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides size_t, t_word

static inline void	baby_memcpy(
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

/**
 * 0. Delegate small buffers (< 1 machine word) to a safe byte-by-byte fallback.
 * 1. Unconditionally copy one unaligned word at the start and one at the end.
 *    This safely covers the edges and eliminates the need for a "tail" loop.
 * 2. Advance both pointers forward to the dest's next aligned memory boundary.
 * 3. Copy the remaining middle section with fast, aligned word-sized writes.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				align;
	unsigned char		*d;
	const unsigned char	*s = src;

	if (n < sizeof(t_word))
	{
		baby_memcpy(dest, src, n);
		return (dest);
	}
	d = dest;
	*(t_word *)d = *(t_word *)s;
	*(t_word *)(d + n - sizeof(t_word)) = *(t_word *)(s + n - sizeof(t_word));
	align = -(t_word)dest & (sizeof(t_word) - 1);
	d += align;
	s += align;
	n -= align;
	while (n >= sizeof(t_word))
	{
		*(t_word *)d = *(t_word *)s;
		d += sizeof(t_word);
		s += sizeof(t_word);
		n -= sizeof(t_word);
	}
	return (dest);
}

/**
 * Slow but portable fallback.
 */
#else

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	baby_memcpy(dest, src, n);
	return (dest);
}

#endif
