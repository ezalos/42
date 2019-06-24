/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:30:59 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/07 14:31:01 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_factorial(int nb)
{
	int i;
	int n;

	i = 1;
	n = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	if (nb > 12)
		return (0);
	while (nb >= i)
	{
		n = n * i;
		i++;
	}
	return (n);
}
