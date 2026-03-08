/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:00:51 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 16:18:01 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	*baby_memchr(
	const unsigned char *mem, unsigned char chr, size_t n
)
{
	while (n--)
	{
		if (*mem == chr)
		{
			return ((void *)mem);
		}
		mem += 1;
	}
	return (NULL);
}

/**
 * If the __may_alias__ attribute is available (to bypass strict aliasing) and
 * the architecture allows unaligned access, use the high-performance version.
 */
#if defined(__GNUC__) && \
	(defined(__x86_64__) || defined(__i386__) || defined(__aarch64__))

static inline void	*scan_word(
	const unsigned char *mem, int chr, t_word broadcast
)
{
	const t_word	ones = (t_word)-1 / 255;
	const t_word	high = ones << 7;
	const t_word	diff = *(t_word *)mem ^ broadcast;

	if ((diff - ones) & ~diff & high)
	{
		return (baby_memchr(mem, chr, sizeof(t_word)));
	}
	return (NULL);
}

/**
 * 0. Delegate small buffers (< 1 machine word) to a safe byte-by-byte fallback.
 * 1. Broadcast the 8-bit 'chr' across a full machine word.
 * 2. Unconditionally check one unaligned word at the start. If a match is found,
 *    the helper delegates to the byte fallback to find its exact position.
 * 3. Advance the pointer forward to the next aligned memory boundary.
 * 4. Scan the remaining middle section with fast, aligned word-sized checks.
 * 5. Unconditionally check one overlapping unaligned word at the end.
 *    This safely covers the tail and eliminates the need for a "tail" loop.
 */
void	*ft_memchr(const void *mem, int chr, size_t n)
{
	const size_t		align = -(t_word)mem & (sizeof(t_word) - 1);
	const unsigned char	*end = (const unsigned char *)mem + n;
	const unsigned char	*ptr = mem;
	t_word				broadcast;
	void				*match;

	if (n < sizeof(t_word))
		return (baby_memchr(mem, chr, n));
	broadcast = (t_word)-1 / 255 * (unsigned char)chr;
	match = scan_word(ptr, chr, broadcast);
	if (match)
		return (match);
	ptr += align;
	n -= align;
	while (n >= sizeof(t_word))
	{
		match = scan_word(ptr, chr, broadcast);
		if (match)
			return (match);
		ptr += sizeof(t_word);
		n -= sizeof(t_word);
	}
	return (scan_word(end - sizeof(t_word), chr, broadcast));
}

/**
 * Slow but portable fallback.
 */
#else

void	*ft_memchr(const void *mem, int chr, size_t n)
{
	return (baby_memchr(mem, chr, n));
}

#endif