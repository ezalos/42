/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:32:01 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/02 17:37:59 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static void 		last_one(void)
{
	while ((*ft_remember_push())->size_b)
		banab((*ft_remember_push())->size_b, 1);
}

void 		banab(int size, int start)
{
	time_exe(__func__);
	int		opt;

	opt = 0;
	if (size <= 0)
		return ;
	if (start)
	{
		if (size > (int)(*ft_remember_push())->size_b)
		{
			last_one();
			return ;
		}
		else
			ba(size);
	}
	size /= 2;
	if (!order_a(size))
	{
		if (-1 == ab(size))
			return ;
		opt = 1;
		banab(size, 0);
	}
	else if (PROGRESS)
	{
		ft_progress(__func__, (*ft_remember_push())->size_a, (*ft_remember_push())->all);
	}
	if (opt)
		banab(size, 1);
}

static int	repeat(void)
{
	time_exe(__func__);
	t_push_swap		*push;
	int				size;

	push = (*ft_remember_push());
	size = push->size_a;
	if (!order_a(push->size_a))
	{
		if (-1 == ab(size))
			return (-1);
		repeat();
		banab(size, 1);
	}
	return (0);
}

int			the_choosen_alg(t_push_swap *push)
{
	time_exe(__func__);
	int		size;

	(void)push;
	size = push->size_a;
	int i;

	i = 0;
	if (PROGRESS)
		ft_progress("banab", 0, (*ft_remember_push())->all);
	repeat();
	return (1);
}
