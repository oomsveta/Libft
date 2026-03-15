/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:32:51 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/13 12:19:04 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__linux__) || defined(__APPLE__)

# include <unistd.h>	// provides size_t, ssize_t, write

#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)

# include <windows.h>

#endif

#if defined(__linux__) || defined(__APPLE__)

void	ft_putchar_fd(char c, int fd)
{
	ssize_t	dummy;

	dummy = write(fd, &c, sizeof c);
	(void)dummy;
}

#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)

void	ft_putchar_fd(char c, HANDLE file_handle)
{
	DWORD	bytes_written;

	bytes_written = 0;
	WriteFile(file_handle, &c, (DWORD)(sizeof c), &bytes_written, NULL);
}

#else

# error "Unsupported target OS"

#endif
