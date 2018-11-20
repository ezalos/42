/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:13:17 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/20 15:05:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		((char*)dest)[i] = ((char*)src)[i];
		if (((char*)src)[i] == (char)c)
			return (src + i));
	}
	return (NULL);
}
