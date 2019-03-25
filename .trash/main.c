/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:36 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/21 18:28:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "head.h"

void	check_binary(void)
{
	char str[] = "Je m'apelle louis";

	ft_printf("Binary on first byte:\t%b\n", str);
	ft_printf("Binary on n bytes :\t%.*b\n", ft_strlen(str), str);
}

void	check_invisible_char(void)
{
	ft_printf("\tThis is\v with invisible char %r\n");
	ft_putendl("");
	ft_printf("\tThis is\v with invisible char put in color %.r\n");
	ft_putendl("");
}

void 	check_fd(void)
{
	int fd;

	fd = open("test", O_RDWR);
	ft_printf("\tThis is\v with invisible char %~.*\n", fd);
}

void	check_colors(void)
{
	int		nb;
	int		red = ft_random(0, 255, (int)&red, (int)&nb);
	int		green = ft_random(0, 255, (int)&green, (int)&nb);
	int		blue = ft_random(0, 255, (int)&blue, (int)&nb);
	float	nd;
	int		test;

	ft_printf("POINTER COLOR %~{!}\n", &nb);
	ft_printf("%~{*;*;*}CHOOSEN COLOR\n", red, green, blue);
	ft_printf("%~{}RESET_COLOR\n", red, green, blue);
	ft_printf("%~{?}RANDOM COLOR\n");
	ft_printf("BACKGROUND POINTER COLOR%~{b!}\n", &nb);
	ft_printf("%~{b*;*;*}CHOOSEN BACKGROUND COLOR\n", red, green, blue);
	ft_printf("%~{}RESET_COLOR\n", red, green, blue);
	ft_printf("%~{b?}RANDOM BACKGROUND COLOR\n", red, green, blue);
}

int		main(void)
{
	check_binary();
	check_invisible_char();
	check_fd();
	check_colors();
	return (0);
}
