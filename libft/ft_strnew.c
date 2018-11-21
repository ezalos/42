/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:12:32 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/21 13:37:38 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*exact;

	if (size < 1)
		return (NULL);
	if (!(exact = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size++;
	while (size > 0)
		exact[size--] = '\0';
	exact[0] = '\0';
	return (exact);
}
