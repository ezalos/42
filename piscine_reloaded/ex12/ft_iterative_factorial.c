/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:50:39 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/05 18:27:47 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_iterative_factorial(int nb)
{
	int result;

	result = 1;
	if (nb == 0)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);
	while (--nb >= 1)
		result *= nb + 1;
	return (result);
}

int main(int ac, char **av)
{
	if (ac == 2)
		printf("%d\n", ft_iterative_factorial(atoi(av[1])));
	return (0);
}
