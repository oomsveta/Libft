/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:09:12 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/01 19:13:03 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If the __may_alias__ attribute is available (to bypass strict aliasing) and
 * the architecture allows unaligned access, use the high-performance version.
 */
#if defined(__GNUC__) && \
	(defined(__x86_64__) || defined(__i386__) || defined(__aarch64__))

void	ft_bzero(void *buffer, size_t size)
{
	const size_t	align = -(uintptr_t)buffer & (sizeof(uintptr_t) - 1);
	unsigned char	*ptr;

	ptr = buffer;
	if (size >= sizeof(uintptr_t))
	{
		*(t_uintptr_alias *)ptr = 0;
		*(t_uintptr_alias *)(ptr + size - sizeof(uintptr_t)) = 0;
		ptr += align;
		size -= align;
		while (size >= sizeof(uintptr_t))
		{
			*(t_uintptr_alias *)ptr = 0;
			ptr += sizeof(uintptr_t);
			size -= sizeof(uintptr_t);
		}
		return ;
	}
	while (size != 0)
	{
		*ptr++ = 0;
		size -= 1;
	}
}

#else

void	ft_bzero(void *buffer, size_t size)
{
	ft_memset(buffer, '\0', size);
}

#endif
