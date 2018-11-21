/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:08 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/21 16:55:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meul, const char *aig, size_t len)
{
	int		walker;
	size_t	limite;

	limite = 0;
	if (*aig == '\0')
		return ((char*)meul);
	if (len < (size_t)ft_strlen(aig))
		return (NULL);
	walker = 0;
	while (meul[limite + walker] != '\0' && limite <= len)
	{
		walker = 0;
		while (aig[walker] == meul[limite + walker])
			if (aig[++walker] == '\0')
				return ((char*)meul + limite);
		limite++;
	}
	return (NULL);
}
