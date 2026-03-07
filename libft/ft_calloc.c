/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:42:15 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/08 00:44:22 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdlib.h>

void	*ft_calloc(size_t nbr_of_elements, size_t element_size)
{
	void	*buffer;
	size_t	total_size;

	if (element_size != 0 && nbr_of_elements > SIZE_MAX / element_size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	total_size = nbr_of_elements * element_size;
	buffer = malloc(total_size);
	if (buffer == NULL)
	{
		return (NULL);
	}
	ft_bzero(buffer, total_size);
	return (buffer);
}
