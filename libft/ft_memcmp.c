/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:13:03 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/22 17:51:45 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((char*)s1)[i] == ((char*)s2)[i] && i < n)
	{
		if ('\0' == ((char*)s2)[i] || ((char*)s1)[i] == '\0')
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	if (ft_isascii((int)(((int*)s1)[i]) && ft_isascii((int)((int*)s1)[i])))
		return (((char*)s1)[i] - ((char*)s2)[i]);
	else
		return (((int*)s1)[i] - ((int*)s2)[i]);
}
