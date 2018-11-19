/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:06:53 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/19 19:40:04 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	*exact;

	if (size < 1 && !(exact = malloc(size)))  //does both instruction are read if size == 0 ?
		return (NULL);
	while (size >= 0)
		exact[size--] = 0;
	return (exact);
}
