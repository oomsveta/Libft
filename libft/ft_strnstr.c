/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:57:18 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 17:46:25 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// provides ft_memchr, ft_memmem, ft_strlen, ft_strnlen, NULL, size_t
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	haystack_len;

	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	needle_len = ft_strlen(needle);
	if (needle_len > len)
	{
		return (NULL);
	}
	haystack_len = ft_strnlen(haystack, len);
	if (needle_len > haystack_len)
	{
		return (NULL);
	}
	if (needle_len == 1)
	{
		return ((char *)ft_memchr(haystack, needle[0], haystack_len));
	}
	return ((char *)ft_memmem(haystack, haystack_len, needle, needle_len));
}
