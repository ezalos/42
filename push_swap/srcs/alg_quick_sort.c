/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:32:01 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/03 18:45:30 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static void			last_one(void)
{
	while ((*ft_remember_push())->size_b)
		banab((*ft_remember_push())->size_b, 1);
}

static void			banab_a_check(int size)
{
	int				opt;

	opt = 0;
	if (!order_a(size))
	{
		if (-1 == ab(size))
			return ;
		opt = 1;
		banab(size, 0);
	}
	else if (PROGRESS)
		ft_progress(__func__,
			(*ft_remember_push())->size_a, (*ft_remember_push())->all);
	if (opt)
		banab(size, 1);
}

void				banab(int size, int start)
{
	static int		last;

	time_exe(__func__);
	if (size <= 0)
		return ;
	if (start)
	{
		if (size > (int)(*ft_remember_push())->size_b)
		{
			last = 1;
			last_one();
			return ;
		}
		else if ((size + 1) / 2 <= INSERT_SWITCH && !last)
		{
			ft_insert_push_ba((size + 1) / 2);
			// if (order_a((*ft_remember_push())->size_a))
				return ;
		}
		// else if ((size + 1) / 2 <= INSERT_SWITCH)
		// {
		// 	ft_insert_push_ba((*ft_remember_push())->size_b);
		// 	// if (order_a((*ft_remember_push())->size_a))
		// 		return ;
		// }
		else
			ba(size);
	}
	size /= 2;
	banab_a_check(size);
}

static int			repeat(void)
{
	t_push_swap		*push;
	int				size;

	time_exe(__func__);
	push = (*ft_remember_push());
	size = push->size_a;
	if (!order_a(push->size_a))
	{
		if (-1 == ab(size))
			return (-1);
		repeat();
		// ft_printf("repeat: %d (%d)\n", size, (*ft_remember_push())->size_b);
		// ft_press_any_key();
		if ((size + 1) / 2 > INSERT_SWITCH)
			banab(size, 1);
		else
			ft_insert_push_ba((size + 1) / 2);
	}
	return (0);
}

int					joep_ab(int size);

void				joep_ba(int size)
{
	int		sent;

	sent = ba(size);
	if (size <= 1)
		return ;
	joep_ab(sent);
	joep_ba(size / 2);
}

int					joep_ab(int size)
{
	int		sent;

	if (size > 1 && !order_a(size))
	{
		sent = ab(size);
		joep_ab(size / 2);
		joep_ba(sent);
	}
	return (0);
}

int					the_choosen_alg(t_push_swap *push)
{
	int				size;

	time_exe(__func__);
	size = push->size_a;
	if (PROGRESS)
		ft_progress("banab", 0, (*ft_remember_push())->all);
	// joep_ab((*ft_remember_push())->size_a);
	repeat();
	return (1);
}
