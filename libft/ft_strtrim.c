/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:55:37 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 17:47:12 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// provides ft_strchr, ft_strlen, ft_strspn, ft_substr, size_t
#include "libft.h"

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
