/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:42:15 by lwicket           #+#    #+#             */
/*   Updated: 2026/10/22 21:36:51 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"		// provides ft_bzero
#include <errno.h>		// provides ENOMEM, errno
#include <stdckdint.h>	// provides ckd_mul
#include <stdlib.h>		// provides malloc, NULL, size_t

[[nodiscard]]
void	*ft_calloc(size_t nbr_of_elements, size_t element_size)
{
	void	*buffer;
	size_t	total_size;

	if (ckd_mul(&total_size, element_size, nbr_of_elements))
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
