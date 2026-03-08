/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:33:16 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 18:59:06 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides malloc, NULL, size_t
#include "libft.h"	// provides ft_strlen

char	*ft_strmapi(const char *str, char (*fn)(unsigned int, char))
{
	size_t	i;
	char	*mapped;

	mapped = malloc(ft_strlen(str) + 1);
	if (!mapped)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		mapped[i] = fn(i, str[i]);
		i += 1;
	}
	mapped[i] = '\0';
	return (mapped);
}
