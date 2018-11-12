/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:54:23 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/12 16:19:46 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		size;
	char	*str;

	i = -1;
	size = ft_strlen(s);
	if (size < start)
		return (NULL);
	if (!(str = (char*)ft_strnew(len)))
		return (NULL);
	while (++i < n)
	{
		str[i] = s[start + i];
		if (s[i] == '\0')
			i = n;
	}
	return (str);
}
