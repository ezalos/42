/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:12:31 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/20 15:11:33 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;
	int		i;

	if (n == 0)
		return (NULL)
	if (!(temp == (char*))malloc(sizeof(char) * n)))
		return (NULL);
	i = -1;
	while (++i < n)
		tmp[i] = ((char*)src)[i];
	while(--n >= 0)
		((char*)dest)[n] = tmp[n];
	free(tmp);
	return (dest);
}
