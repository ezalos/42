/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:12:31 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/22 17:26:39 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (n == 0)
		return (dest);
	if (!(tmp = (char*)malloc(sizeof(char) * n)))
		return (NULL);
	while (i < n)
	{
		tmp[i] = ((char*)src)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		((char*)dest)[i] = tmp[i];
		i++;
	}
	((char*)dest)[0] = tmp[0];
	free(tmp);
	return (dest);
}
