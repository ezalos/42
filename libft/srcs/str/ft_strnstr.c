/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:08 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/13 15:20:06 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

char	*ft_strnstr(const char	*meule_de_foin, const char *aiguille, size_t len);
{
	int		walker;
	size_t	limite;

	limite = 0;
	if (*aiguille == '\0')
		return (meule_de_foin);
	if (len < ft_strlen(aiguille))
		return (NULL);
	while (meule_de_foin[limite + walker] != '\0' && limite <= len)
	{
		walker = 0;
		while (aiguille[walker] == meule_de_foin[limite + walker])
			if (aiguille[++walker] == '\0')
				return (&(meule_de_foin[limite]));
		limite++;
	}
	return (NULL);
}
