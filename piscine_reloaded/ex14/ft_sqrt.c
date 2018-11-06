/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:44:49 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/05 19:02:02 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return(0);
	while (i <= nb/i && i * i != nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}

int main(int ac, char **av)
{
	if (ac == 2)
		printf("%d\n", ft_sqrt(atoi(av[1])));
	return (0);
}
