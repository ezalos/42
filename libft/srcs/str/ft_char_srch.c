/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_srch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:39:11 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/16 22:07:34 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_char_srch(char src, char *dlt)
{
	while (*dlt)
	{
		if (src == *dlt)
			return (1);
		dlt++;
	}
	return (0);
}
