/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:29:00 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/21 13:57:42 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recur(int n, int fd)
{
	if (n != 0)
	{
		recur(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int	size;

	size = ft_intlen(n);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
	}
	recur(n, fd);
}
