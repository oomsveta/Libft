/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 22:42:39 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/13 12:28:11 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides size_t, t_aligned_word, t_word

static inline void	byte_by_byte_memset(
	unsigned char *buffer, unsigned char byte, size_t size
)
{
	while (size--)
	{
		*buffer++ = byte;
	}
}

/**
 * 0. Delegate small buffers (< 1 machine word) to a safe byte-by-byte fallback.
 * 1. Broadcast the 8-bit 'byte' across a full machine word (filler).
 * 2. Unconditionally write one unaligned word at the start and one at the end.
 *    This safely covers the edges and eliminates the need for a "tail" loop.
 * 3. Advance the pointer forward to the next aligned memory boundary.
 * 4. Fill the remaining middle section with fast, aligned word-sized writes.
 */
void	*ft_memset(void *buffer, int byte, size_t size)
{
	t_word			filler;
	unsigned char	*ptr;
	size_t			align;

	if (size < sizeof(t_word))
	{
		byte_by_byte_memset(buffer, byte, size);
		return (buffer);
	}
	ptr = buffer;
	filler = (t_word)-1 / 255 * (unsigned char)byte;
	*(t_word *)ptr = filler;
	*(t_word *)(ptr + size - sizeof(t_word)) = filler;
	align = -(uintptr_t)buffer & (sizeof(t_word) - 1);
	ptr += align;
	size -= align;
	while (size >= sizeof(t_word))
	{
		*(t_aligned_word *)ptr = filler;
		ptr += sizeof(t_word);
		size -= sizeof(t_word);
	}
	return (buffer);
}
