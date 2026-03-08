/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:34:40 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 17:43:39 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>	// provides ENOMEM, errno
#include <stdlib.h>	// provides malloc, NULL, size_t
#include "libft.h"	// provides ft_memcpy, ft_strlen

char	*ft_strjoin(const char *s1, const char *s2)
{
	const size_t	len1 = ft_strlen(s1);
	const size_t	len2 = ft_strlen(s2);
	char			*joined;

	if (len1 > SIZE_MAX - len2 - 1)
	{
		errno = ENOMEM;
		return (NULL);
	}
	joined = malloc(len1 + len2 + 1);
	if (!joined)
	{
		return (NULL);
	}
	ft_memcpy(joined, s1, len1);
	ft_memcpy(joined + len1, s2, len2 + 1);
	return (joined);
}
