/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:25:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 15:59:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void			visual_checker(t_push_swap *push)
{
	int		i;

	ft_place_cursor(0, 0);
	print_header(push);
	print_stacks(push);
	if (SLOW)
	{
		i = -1;
		while (++i < SLOW)
			ft_wait_pls(0);
	}
}

int				exe_actions(t_push_swap *push)
{
	int			r_v;

	print_push_swap(push);
	if (0 >= get_next_line(0, &push->instruction))
		return (0);
	while (push->instruction[0] != '\0')
	{
		if (-1 == (r_v = execute_order_66(push)))
			return (-1);
		if (r_v)
			push->count++;
		if (VISUAL_CHECKER == 1
		|| (VISUAL_CHECKER == 2 && (JUMP && !(push->count % JUMP))))
			visual_checker(push);
		else if (VISUAL_MODE)
			print_push_swap(push);
		ft_strdel(&push->instruction);
		if (0 >= get_next_line(0, &push->instruction))
			return (0);
	}
	return (push->count);
}
