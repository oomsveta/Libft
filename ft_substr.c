/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:15:18 by lwicket           #+#    #+#             */
/*   Updated: 2026/09/04 14:11:35 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides malloc, NULL, size_t
#include "libft.h"	// provides ft_memcpy

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

[[nodiscard]]
char	*ft_substr(const char *str, unsigned int start, size_t max_len)
{
	size_t	len;
	char	*substr;

	str += ft_strnlen(str, start);
	len = ft_strnlen(str, max_len);
	substr = malloc(len + 1);
	if (!substr)
	{
		return (NULL);
	}
	ft_memcpy(substr, str, len);
	substr[len] = '\0';
	return (substr);
}
