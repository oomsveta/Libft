/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 20:28:16 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 17:42:10 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// provides free, malloc, NULL, size_t
#include "libft.h"	// provides ft_strchrnul, ft_substr

static char	*skip_char(const char *str, char c)
{
	while (*str == c)
	{
		str += 1;
	}
	return ((char *)str);
}

static size_t	count_words(const char *str, char separator)
{
	size_t	nbr_of_words;

	nbr_of_words = 0;
	while (*str)
	{
		str = skip_char(str, separator);
		nbr_of_words += 1;
		str = ft_strchrnul(str, separator);
	}
	return (nbr_of_words);
}

static void	free_all(char *words[], size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(words[i]);
	}
	free(words);
}

char	**ft_split(const char *str, char separator)
{
	const char	*end_ptr;
	char		**words;
	size_t		i;

	words = malloc(sizeof(*words) * (count_words(str, separator) + 1));
	if (!words)
	{
		return (NULL);
	}
	i = 0;
	while (*str != '\0')
	{
		str = skip_char(str, separator);
		end_ptr = ft_strchrnul(str, separator);
		words[i] = ft_substr(str, 0, end_ptr - str);
		if (!words[i])
		{
			free_all(words, i);
			return (NULL);
		}
		i += 1;
		str = end_ptr;
	}
	words[i] = NULL;
	return (words);
}
