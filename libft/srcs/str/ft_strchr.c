/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:12:04 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/16 22:14:39 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		walker;

	if (c == 0)
		return (&(s[ft_strlen(s)]));
	while (*s != c)
		if (*(s++) == 0)
			return (NULL);
	return (s);
}
