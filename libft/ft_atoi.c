/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:40:31 by lwicket           #+#    #+#             */
/*   Updated: 2026/05/03 20:06:46 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>	// provides bool
#include "libft.h"		// provides ft_strspn

int	ft_atoi(const char *nptr)
{
	bool			is_negative;
	unsigned int	acc;
	unsigned int	digit;

	nptr += ft_strspn(nptr, " \n\t\r\v\f");
	is_negative = *nptr == '-';
	nptr += is_negative || *nptr == '+';
	acc = 0;
	digit = *nptr++ ^ '0';
	while (digit < 10)
	{
		acc = acc * 10 + digit;
		digit = *nptr++ ^ '0';
	}
	if (is_negative)
	{
		return (-acc);
	}
	return (+acc);
}
