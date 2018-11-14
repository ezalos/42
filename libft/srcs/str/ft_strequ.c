/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:42:07 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/14 11:52:07 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == *s2 && *s1 == '\0')
			return (1);
		s1++;
		s2++;
	}
	return (0);
}
