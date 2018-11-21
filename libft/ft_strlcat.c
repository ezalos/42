/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:44 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/21 16:49:17 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_n(size_t size, char *str)
{
	size_t	i;

	i = -1;
	while (i <= size)
		while (str[++i])
			if (str[i] == '\0')
				if (i == size)
					return (size);
	return (i);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	i;

	size_dst = ft_strlen_n(size, dst);
	if (size_dst == size)
		return (size);
	size_src = ft_strlen_n(size, (char*)src);
	if (size_src >= size - size_dst)
		return (size_dst + size_src - 1);
	i = -1;
	while (++i < size_src)
		dst[size_dst + i] = src[i];
	dst[size + i] = '\0';
	return (size + i);
}
