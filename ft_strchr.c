/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:05:07 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/01 20:39:16 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// provides NULL

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

char	*ft_strchrnul(const char *str, int chr)
{
	chr = (unsigned char)chr;
	while (*str && *(unsigned char *)str != chr)
	{
		str += 1;
	}
	return ((char *)str);
}

size_t	ft_strspn(const char *str, const char *spn)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		if (!ft_strchr(spn, str[len]))
		{
			return (len);
		}
		len += 1;
	}
	return (len);
}
