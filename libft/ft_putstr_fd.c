/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:32:33 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/12 20:48:15 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>	// provides EINTR, errno
#include <unistd.h>	// provides size_t, ssize_t, write
#include "libft.h"	// provides ft_strlen

void	ft_putstr_fd(char *str, int fd)
{
	ssize_t			total_written;
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
