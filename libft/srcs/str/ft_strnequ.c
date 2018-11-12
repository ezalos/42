/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:49:47 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/12 16:18:18 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && i <= n)
	{
		if (s1[i] != s2[i])
			return (0);
		if (s1[i] == s2[i] && s1[i] == '\0')
			return (1);
		i++;
	}
	return (1);
}
