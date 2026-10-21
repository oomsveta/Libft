/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:05:07 by lwicket           #+#    #+#             */
/*   Updated: 2026/09/30 17:17:30 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// provides size_t
#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	chr = (unsigned char)chr;
	while (*(unsigned char *)str != chr)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str += 1;
	}
	return ((char *)str);
}
