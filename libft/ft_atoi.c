/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:13:53 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/11 18:04:21 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	long long	nb;
	int			num;
	int			neg;

	neg = 1;
	num = 0;
	nb = 0;
	if (str == NULL || *str == '\0')
		return (0);
	while (ft_char_srch(*str, "\t\n\r\v\f \0"))
		str++;
	if (*str == '-')
	{
		neg = -neg;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		nb = (nb * 10) + (*(str++) - '0');
	nb *= neg;
	num = (int)nb;
	return (num);
}
