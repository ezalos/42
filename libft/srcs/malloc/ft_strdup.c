/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:48 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/13 15:02:04 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		size;

	size = ft_strlen(src);
	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = -1;
	dest[size] = '\0';
	while (++i < size)
		dest[i] = src[i];
	return (dest);
}
