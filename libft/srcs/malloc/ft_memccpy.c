/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:13:17 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/16 21:58:36 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		(int)dest[i] = (int)src[i];
		if ((int)src[i] == c)
			return (&(src[i + 1]));
	}
	return (NULL);
}
