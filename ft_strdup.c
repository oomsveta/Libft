/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 21:08:18 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/01 21:56:04 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides free, malloc
#include "libft.h"

char	*ft_strdup(const char *str)
{
	const size_t	size = ft_strlen(str) + 1;
	char			*dup;

	dup = malloc(size);
	if (!dup)
	{
		return (NULL);
	}
	return (ft_memcpy(dup, str, size));
}
