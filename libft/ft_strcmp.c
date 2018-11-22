/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:59 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/22 19:51:48 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	while (*(s1++) == *(s2++))
		if (*(s1 - 1) == '\0' || *(s2 - 1) == '\0')
			return (0);
	return ((unsigned char)*(s1 - 1) - (unsigned char)*(s2 - 1));
}
