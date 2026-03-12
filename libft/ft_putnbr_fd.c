/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:31:46 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/12 20:49:31 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>	// provides CHAR_BIT
#include <unistd.h>	// provides write
#include "libft.h"	// provides ft_abs, ft_putstr_fd

void	ft_putnbr_fd(int n, int fd)
{
	char			buffer[(sizeof(int) * CHAR_BIT - 1) * 28 / 93 + 3];
	char			*nptr;
	unsigned int	acc;

	nptr = buffer + sizeof buffer;
	acc = ft_abs(n);
	*--nptr = '\0';
	while (acc >= 10)
	{
		*--nptr = acc % 10 | '0';
		acc /= 10;
	}
	*--nptr = acc % 10 | '0';
	if (n < 0)
	{
		*--nptr = '-';
	}
	ft_putstr_fd(nptr, fd);
}
