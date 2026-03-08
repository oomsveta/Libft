/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:32:07 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 17:43:24 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>	// provides size_t

void	ft_striteri(char *str, void (*fn)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		fn(i, &str[i]);
		i += 1;
	}
}
