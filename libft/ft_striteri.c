/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:32:07 by lwicket           #+#    #+#             */
/*   Updated: 2026/09/19 23:25:46 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
