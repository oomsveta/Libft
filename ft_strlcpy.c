/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:24:04 by lwicket           #+#    #+#             */
/*   Updated: 2026/09/30 17:05:06 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// provides size_t
#include "libft.h"	// provides ft_strlen

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
	{
		return (ft_strlen(src));
	}
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (i + ft_strlen(&src[i]));
}
