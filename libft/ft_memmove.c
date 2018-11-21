/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:12:31 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/21 13:40:58 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;
	size_t	i;

	if (n == 0)
		return (NULL);
	if (!(tmp = (char*)malloc(sizeof(char) * n)))
		return (NULL);
	i = -1;
	while (++i < n)
		tmp[i] = ((char*)src)[i];
	while (--n > 0)
		((char*)dest)[n] = tmp[n];
	((char*)dest)[0] = tmp[0];
	free(tmp);
	return (dest);
}
