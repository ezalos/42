/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:03:31 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/20 15:13:34 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((char*)s)[n] = (char)c;
	return (str);
}
