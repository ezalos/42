/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:14 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/20 19:39:53 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
	{
		dest[i] = src[i];
		if (dest[i] == '\0')
			while (++i < n)
				dest[i] = '\0';
	}
	return (dest);
}
