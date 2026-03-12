/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:32:51 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/12 20:43:02 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides size_t, ssize_t, write

void	ft_putchar_fd(char c, int fd)
{
	ssize_t	dummy;

	dummy = write(STDOUT_FILENO, &c, sizeof c);
	(void)dummy;
}
