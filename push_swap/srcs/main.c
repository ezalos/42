/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/03 16:57:48 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		main(int ac, char **av)
{
	t_push_swap		*push;

	time_exe(__func__);
	if (VISUAL_MODE)
		CLEAR_SCREEN
	if (ac <= 1)
		return (ft_putstr_r0("Error\n"));
	if (!(push = setup_tab(ac - 1, av)))
		return (ft_putstr_r0("Error\n"));
	ft_save_arguments("./tests/last", ac, av);
	lets_solve(push);
	traduction();
	if (COUNT)
		ft_printf("%d\n", push->count);
	time_exe(__func__);
	if (is_it_good(push))
	{
		ft_save_file_exit_ok(push, ac, av);
		return (ft_putstr_r0("OK\n"));
	}
	ft_save_file_exit_ko(ac, av);
	return (ft_putstr_r0("KO\n"));
}
