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

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)

# include <windows.h>
#endif

#include <limits.h>	// provides CHAR_BIT
#include "libft.h"	// provides ft_abs, ft_putstr_fd

#if defined(__linux__) || defined(__APPLE__)

void	ft_putnbr_fd(int n, int file)
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)

void	ft_putnbr_fd(int n, HANDLE file)
#else

# error "Unsupported target OS"

#endif

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
	ft_putstr_fd(nptr, file);
}
