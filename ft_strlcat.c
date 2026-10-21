/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:32:58 by lwicket           #+#    #+#             */
/*   Updated: 2026/09/30 17:04:59 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// provides size_t
#include "libft.h"	// provides ft_strlcpy, ft_strlen

static size_t	ft_strnlen(const char *str, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n && str[len] != '\0')
	{
		len += 1;
	}
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const size_t	dest_len = ft_strnlen(dest, size);

	if (dest_len == size)
	{
		return (dest_len + ft_strlen(src));
	}
	return (dest_len + ft_strlcpy(dest + dest_len, src, size - dest_len));
}
