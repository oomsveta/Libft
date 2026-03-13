/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:09:12 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/13 15:35:21 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides ft_memset, size_t, t_word

/**
 * 1. Unconditionally write an unaligned word of zeros at the start and end.
 *    This safely covers the edges and eliminates the need for a "tail" loop.
 * 2. Advance the pointer forward to the next aligned memory boundary.
 * 3. Fill the remaining middle section with fast, aligned word-sized zeros.
 */
void	ft_bzero(void *buffer, size_t size)
{
	const size_t	align = -(uintptr_t)buffer & (sizeof(t_word) - 1);
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
		*(t_aligned_word *)ptr = 0;
		ptr += sizeof(t_word);
		size -= sizeof(t_word);
	}
}
