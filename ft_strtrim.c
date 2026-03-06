/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:55:37 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/01 20:32:57 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides ft_strchr, ft_strlen, ft_strspn, ft_substr

char	*ft_strtrim(char const *str, char const *chars)
{
	const size_t	start = ft_strspn(str, chars);
	size_t			end;

	end = ft_strlen(str);
	while (end > start && ft_strchr(chars, str[end]))
	{
		end -= 1;
	}
	return (ft_substr(str, start, end - start));
}
