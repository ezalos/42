/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:08 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/16 22:15:00 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *meule, const char *aiguille, size_t len)
{
	int		walker;
	size_t	limite;

	limite = 0;
	if (*aiguille == '\0')
		return (meule);
	if (len < ft_strlen(aiguille))
		return (NULL);
	while (meule[limite + walker] != '\0' && limite <= len)
	{
		walker = 0;
		while (aiguille[walker] == meule[limite + walker])
			if (aiguille[++walker] == '\0')
				return (&(meule[limite]));
		limite++;
	}
	return (NULL);
}
