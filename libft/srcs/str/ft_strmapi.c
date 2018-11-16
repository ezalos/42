/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:38:45 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/12 16:18:57 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
	int		size;
	char	*str;

	size = ft_strlen(s);
	if (size < 1 || !(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[++size] = 0;
	while (--size >= 0)
		str[size] = f(size, s[size]);
	return (str);
}
