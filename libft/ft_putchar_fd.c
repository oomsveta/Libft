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

#include <unistd.h>	// provides size_t, ssize_t, write

void	ft_putchar_fd(char c, int fd)
{
	ssize_t	dummy;

	dummy = write(fd, &c, sizeof c);
	(void)dummy;
}
