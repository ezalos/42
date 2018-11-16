/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:03 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/13 15:29:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		walker;

	walker = ft_strlen(s) + 1;
	if (c == 0)
		return (&(s[walker - 1]));
	while (s[--walker] != c)
		if (walker == 0)
			return (NULL);
	return (&(s[walker]));
}
