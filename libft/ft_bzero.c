/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:09:12 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 15:55:39 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides ft_memset, size_t, t_word

/**
 * If the __may_alias__ attribute is available (to bypass strict aliasing) and
 * the architecture allows unaligned access, use the high-performance version.
 */
#if defined(__GNUC__) && \
	(defined(__x86_64__) || defined(__i386__) || defined(__aarch64__))

/**
 * 0. Delegate small buffers (< 1 machine word) to a safe byte-by-byte fallback.
 * 1. Unconditionally write an unaligned word of zeros at the start and end.
 *    This safely covers the edges and eliminates the need for a "tail" loop.
 * 2. Advance the pointer forward to the next aligned memory boundary.
 * 3. Fill the remaining middle section with fast, aligned word-sized zeros.
 */
void	ft_bzero(void *buffer, size_t size)
{
	const size_t	align = -(t_word)buffer & (sizeof(t_word) - 1);
	unsigned char	*ptr;

	if (size < sizeof(t_word))
	{
		ft_memset(buffer, '\0', size);
		return ;
	}
	ptr = buffer;
	*(t_word *)ptr = 0;
	*(t_word *)(ptr + size - sizeof(t_word)) = 0;
	ptr += align;
	size -= align;
	while (size >= sizeof(t_word))
	{
		*(t_word *)ptr = 0;
		ptr += sizeof(t_word);
		size -= sizeof(t_word);
	}
}

/**
 * Slow but portable fallback.
 */
#else

void	ft_bzero(void *buffer, size_t size)
{
	ft_memset(buffer, '\0', size);
}

#endif
