/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:06:53 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/22 19:32:30 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	*exact;

	if ((size < 1) || !(exact = malloc(size)))
		return (NULL);
	while (size > 0)
		exact[size--] = 0;
	exact[0] = 0;
	return (exact);
}
