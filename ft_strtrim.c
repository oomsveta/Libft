/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:55:37 by lwicket           #+#    #+#             */
/*   Updated: 2026/09/30 17:03:57 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// provides size_t
#include "libft.h"	// provides ft_strchr, ft_strlen, ft_substr

static size_t	ft_strspn(const char *str, const char *spn)
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

[[nodiscard]]
char	*ft_strtrim(const char *str, const char *chars)
{
	const size_t	start = ft_strspn(str, chars);
	size_t			end;

	end = ft_strlen(str);
	while (end > start && ft_strchr(chars, str[end - 1]))
	{
		end -= 1;
	}
	return (ft_substr(str, start, end - start));
}
