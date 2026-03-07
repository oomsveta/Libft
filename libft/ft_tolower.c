/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:59:35 by lwicket           #+#    #+#             */
/*   Updated: 2026/03/01 19:00:49 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static inline int	ft_isupper(int c)
{
	return ((unsigned int)c - 'A' < 26u);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
	{
		return (c ^ 0x20);
	}
	return (c);
}
