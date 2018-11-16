/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:10:54 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/13 15:20:11 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

char	*ft_strstr(const char *meule_de_foin, const char *aiguille);
{
	int		walker;

	if (*aiguille == '\0')
		return (meule_de_foin);
	if (ft_strlen(meule_de_foin) < ft_strlen(aiguille))
		return (NULL);
	while (meule_de_foin[walker] != '\0')
	{
		walker = 0;
		while (aiguille[walker] == meule_de_foin[walker])
			if (aiguille[++walker] == '\0')
				return (meule_de_foin);
		meule_de_foin++;
	}
	return (NULL);
}