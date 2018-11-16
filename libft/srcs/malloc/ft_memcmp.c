/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:13:03 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/14 12:27:25 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && i <= n)
	{
		if (s1[i] == s2[i] && s1[i] == '\0')
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
