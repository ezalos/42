/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:13:07 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/14 12:36:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		walker;

	while (*s != c && --n >= 0)
		if (*(s++) == 0)
			return (NULL);
	if (n == 0)
		return (NULL);
	return (s);
}
