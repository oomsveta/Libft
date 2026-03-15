/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:33:06 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 17:40:50 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)

# include <windows.h>

#endif

#if defined(__linux__) || defined(__APPLE__)

void	ft_putendl_fd(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}

#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)

void	ft_putendl_fd(char *str, HANDLE file_handle)
{
	ft_putstr_fd(str, file_handle);
	ft_putchar_fd('\r', file_handle);
	ft_putchar_fd('\n', file_handle);
}

#else

# error "Unsupported target OS"

#endif
