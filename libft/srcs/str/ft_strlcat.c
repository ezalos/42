/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:44 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/13 18:29:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

static	int	ft_strlen_n(size_t size, char *str, int size_str)
{
	int	i;

	i = -1;
	while (i <= size)
		while (str[++i])
			if (str[i] == '\0')
				if (i == size)
					return (size);
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	size_dst;
	int	size_src;
	int	i;

	size_dst = ft_strlen_n(size, dst, size_dst);
	if (size_dst == size)
		return (size);
	size_src = ft_strlen_n(size, src, size_src);
	if (size_src >= size - size_dst)
		return (size_dst + size_src - 1);
	i = -1;
	while (++i < size_src)
		dest[size_dst + i] = src[i];
	dest[size + i] = '\0';
	return (size + i);
}
