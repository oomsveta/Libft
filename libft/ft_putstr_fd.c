/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:32:33 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/13 12:20:57 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"		// provides ft_strlen

#if defined(__linux__) || defined(__APPLE__)

# include <errno.h>		// provides EINTR, errno
# include <unistd.h>	// provides size_t, ssize_t, write

#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)

# include <windows.h>

#endif

#if defined(__linux__) || defined(__APPLE__)

void	ft_putstr_fd(char *str, int fd)
{
	size_t			total_written;
	ssize_t			bytes_written;
	const size_t	len = ft_strlen(str);

	total_written = 0;
	while (total_written < len)
	{
		bytes_written = write(fd, str, ft_strlen(str));
		if (bytes_written == -1)
		{
			if (errno == EINTR)
			{
				continue ;
			}
			return ;
		}
		total_written += bytes_written;
	}
}

#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__)

void	ft_putstr_fd(char *str, HANDLE file_handle)
{
	const DWORD	len = (DWORD)ft_strlen(str);
	DWORD		bytes_written;

	bytes_written = 0;
	WriteFile(file_handle, str, len, &bytes_written, NULL);
}

#else

# error "Unsupported target OS"

#endif
