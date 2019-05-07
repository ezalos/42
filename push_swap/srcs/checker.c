/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:43:28 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/06 19:28:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		main(int ac, char **av)
{
	t_push_swap		*push;

	if (VISUAL_CHECKER)
		_CLEAR_SCREEN;
	if (ac <= 1)
		return (ft_putstr_r0_fd("Error\n", 2));
	if (!(push = setup_tab(ac - 1, av)))
		return (ft_putstr_r0_fd("Error\n", 2));
	if (!is_it_good(push))
		write_it_yourself(push);
	if (VISUAL_CHECKER)
		visual_checker(push);
	if (is_it_good(push))
	{
		ft_clean_garbage();
		return (ft_putstr_r0_fd("OK\n", 1));
	}
	ft_clean_garbage();
	return (ft_putstr_r0_fd("KO\n", 1));
}
