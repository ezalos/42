/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:38:58 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/05 18:43:08 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);
	return (nb * ft_recursive_factorial(nb - 1));
}

int main(int ac, char **av)
{
	if (ac == 2)
		printf("%d\n", ft_recursive_factorial(atoi(av[1])));
	return (0);
}
