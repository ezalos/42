/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:14 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/13 17:31:22 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		dest[i] = src[i];
		if (dest[i] == '\0')
			while (++i < n)
				dest[i] = '\0';
	}
	return (dest);
}
