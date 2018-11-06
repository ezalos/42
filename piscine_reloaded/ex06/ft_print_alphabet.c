/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:55:36 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/05 17:30:34 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_alphabet(void)
{
	char a;

	a = 'a';
	while (a <= 'z')
		ft_putchar(a++);
}

int main()
{
	ft_print_alphabet();
	return (0);
}
