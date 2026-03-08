/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:32:33 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 17:41:37 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>	// provides write
#include "libft.h"	// provides ft_strlen

void	ft_putstr_fd(char *str, int fd)
{
	(void)write(fd, str, ft_strlen(str));
}
