/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:15:18 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/07 15:09:23 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides malloc, NULL
#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t max_len)
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
