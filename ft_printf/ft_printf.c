/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:47 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/24 21:45:52 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./head.h"

int		ft_printf(const char *format, ...)
{
	t_print		print;
	va_list		ap;
//	char		*str;
	int			ptr_nb;
//	int			nb;

	va_list(ap);
	va_start(ap, format);
	ptr_nb = va_arg(ap, int);
	ft_putstr("->ft_printf: ");
	ft_putnbr(ptr_nb);
	ft_putendl("");
	va_end(ap);
	return (1);
}

int		parsing(const char *format, va_list ap)
{

}
