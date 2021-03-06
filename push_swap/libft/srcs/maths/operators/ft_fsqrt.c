/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fsqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:14:46 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/18 17:19:03 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_fsqrt(int nb, int limite)
{
	float	x;
	float	n;

	n = (float)nb;
	if (nb <= 0)
		return (0);
	x = n / 2;
	if (limite == 0)
		limite = 30;
	while (--limite)
		x = (x + (n / x)) / 2;
	return (x);
}
