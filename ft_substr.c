/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:15:18 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/02 09:21:06 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides malloc, NULL
#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	size;
	char	*substr;

	str += ft_strnlen(str, start);
	size = ft_strnlen(str, len) + 1;
	substr = malloc(size);
	if (!substr)
	{
		return (NULL);
	}
	ft_memcpy(substr, str, size);
	return (substr);
}
