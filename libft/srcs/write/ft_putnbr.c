/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:48:33 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/12 16:17:38 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

static void recur(n)
{
	if (n != 0)
	{
		recur(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void	ft_putnbr(int n)
{
	int	size;

	size = ft_intlen(n);
	if (n < 0)
	{
		ft_putchar('-');
	}
	recur(n);
}
