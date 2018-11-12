/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:09:01 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/12 16:20:35 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

static	void ft_putnbr_str(int i, int n, char *nb)
{
	while (n != 0)
	{
		nb[i--] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		size;
	int		neg;
	int		i;

	neg = 1;
	if (n > 0)
		neg = 0;
	size = ft_intlen(n);
	if (!(nb = ft_strnew(size + neg))
		return (NULL);
	if (neg == 1)
		nb[0] = '-';
	i = size + neg;
	ft_putnbr_str(i, n, nb);
	return (nb);
}
