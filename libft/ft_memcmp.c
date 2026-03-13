/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:03:42 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/13 12:27:36 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides size_t, uintptr_t, t_aligned_word, t_word

static inline int	byte_by_byte_memcmp(
	const unsigned char *s1, const unsigned char *s2, size_t n
)
{
	while (n--)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1 += 1;
		s2 += 1;
	}
	return (0);
}

/**
 * 0. Delegate small buffers (< 1 machine word) to a safe byte-by-byte fallback.
 * 1. Unconditionally compare one unaligned word at the start. If they differ,
 *    delegate to the byte fallback to find the exact differing byte.
 * 2. Advance both pointers forward to align the first pointer to memory.
 * 3. Compare the remaining middle section with fast, word-sized checks.
 * 4. Unconditionally compare one overlapping unaligned word at the end.
 *    This safely covers the tail and eliminates the need for a "tail" loop.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				align;
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;

	if (n < sizeof(t_word))
		return (byte_by_byte_memcmp(p1, p2, n));
	if (*(t_word *)p1 != *(t_word *)p2)
		return (byte_by_byte_memcmp(p1, p2, sizeof(t_word)));
	align = -(uintptr_t)s1 & (sizeof(t_word) - 1);
	p1 += align;
	p2 += align;
	n -= align;
	while (n >= sizeof(t_word))
	{
		if (*(t_aligned_word *)p1 != *(t_word *)p2)
			return (byte_by_byte_memcmp(p1, p2, sizeof(t_word)));
		p1 += sizeof(t_word);
		p2 += sizeof(t_word);
		n -= sizeof(t_word);
	}
	p1 = (p1 + n) - sizeof(t_word);
	p2 = (p2 + n) - sizeof(t_word);
	if (*(t_word *)p1 != *(t_word *)p2)
		return (byte_by_byte_memcmp(p1, p2, sizeof(t_word)));
	return (0);
}
