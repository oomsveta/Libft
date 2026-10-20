/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:33:29 by lwicket           #+#    #+#             */
/*   Updated: 2026/09/30 17:06:20 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// provides size_t
#include "libft.h"	// provides ft_strlen

char	*ft_strrchr(const char *str, int chr)
{
	size_t	n;

	n = ft_strlen(str) + 1;
	chr = (unsigned char)chr;
	while (n--)
	{
		if (((unsigned char *)str)[n] == chr)
		{
			return ((char *)&str[n]);
		}
	}
	return (NULL);
}
