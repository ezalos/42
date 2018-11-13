/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:12:04 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/13 15:31:20 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		walker;

	if (c == 0)
		return (&(s[ft_strlen(s)]));
	while (s != c)
		if (s++ == 0)
			return (NULL);
	return (s);
}
