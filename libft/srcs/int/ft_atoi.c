/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:13:53 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/16 22:17:25 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_atoi(char *str)
{
	char	dlt[7];
	long	nb;
	int		num;
	int		neg;

	neg = 1;
	num = 0;
	dlt = ft_strcpy(dlt, "\t\n\r\v\f \0");
	while (ft_char_srch(*str, dlt))
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
	if (nb >= -2147483648 && nb <= 2147483647)
		num = nb;
	return (num);
}
