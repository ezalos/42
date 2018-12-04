/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:54:32 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/04 14:29:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		size;
	int		end;
	char	*new;

	while (ft_char_srch(*s, " \n\t\0"))
		s++;
	if (!*s)
		return (ft_memalloc(1));
	end = 0;
	size = ft_strlen(s);
	while (ft_char_srch(s[size - end - 1], " \n\t\0"))
		end++;
	if (!(new = ft_strsub(s, 0, size - end)))
		return (NULL);
	return (new);
}
