/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:32:33 by lwicket           #+#    #+#             */
/*   Updated: 2026/10/20 20:35:21 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides ft_strlen
#include <unistd.h>	// provides size_t, ssize_t, write

void	ft_putstr_fd(char *str, int fd)
{
	size_t			total_written;
	ssize_t			bytes_written;
	const size_t	len = ft_strlen(str);

	total_written = 0;
	while (total_written < len)
	{
		bytes_written = write(fd, str + total_written, len - total_written);
		if (bytes_written == -1)
		{
			return ;
		}
		total_written += bytes_written;
	}
}
