/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:32:01 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/04 14:59:18 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int					master_ba(int size)
{
	int		sent;

	sent = ba(size);
	if (size <= 1)
		return (size);
	master_ab(sent);
	master_ba(size - sent);
	return (sent);
}

int					master_ab(int size)
{
	int		sent;

	sent = 0;
	if (size > 1 && !order_a(size))
	{
		sent = ab(size);
		master_ab(size + sent);
		master_ba(-sent);
	}
	else if (size && PROGRESS)
		ft_progress(__func__,
			(*ft_remember_push())->size_a, (*ft_remember_push())->all);
	return (0);
}

int					the_choosen_alg(t_push_swap *push)
{
	int				size;

	time_exe(__func__);
	size = push->size_a;
	if (PROGRESS)
		ft_progress("AB_BA", 0, (*ft_remember_push())->all);
	master_ab((*ft_remember_push())->size_a);
	return (1);
}
