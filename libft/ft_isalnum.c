/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwicket <lwicket@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 22:23:39 by lwicket           #+#    #+#             */
/*   Updated: 2026/09/19 23:23:00 by lwicket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	// provides ft_isalpha, ft_isdigit

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
