/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:54:32 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/12 16:18:11 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

char		*ft_strtrim(char const *s)
{
	int		size;
	int		end;
	char	dlt[4];
	char	*new;

	dlt = " \n\t\0";
	while (ft_char_srch(*s, dlt))
		s++;
	end = 0;
	size = ft_strlen(s);
	while (ft_char_srch(s[size - end], dlt))
		end++;
	if (!(new = ft_strsub(s, 0, size - end)))
		return (NULL);
	return (new);
}
