/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_choosen_alg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:32:01 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/10 23:06:52 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static void			lets_see(int mode, int size)
{
	return ;
	print_push_swap((*ft_remember_push()));
	return ;
	if (mode == 0)
		ft_printf("%~{?}%s size: (%d)\n\n\n", "REPEAT", size);
	else if (mode == 1)
		ft_printf("%~{?}\nSTART BA(%d)\tif(%d)      \n\n", size, !order_a(size));
	else if (mode == -1)
		ft_printf("%~{?}\n!START      \tif:%d      \n\n", !order_a(size));
	else if (mode == 2)
		ft_printf("%~{?}\n\n\tAB(%d)\n", size);
	else if (mode == -2)
		ft_printf("%~{?}BANAB OF (%d)\n\n\n", size);
	if (mode >= 0)
		ft_press_any_key();
}

void 		banab(int size, int start);

static void 		last_one(void)
{
	while ((*ft_remember_push())->size_b)
		banab((*ft_remember_push())->size_b, 1);
}

void 		banab(int size, int start)
{
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
	if (opt)
		banab(size, 1);
}

static int	repeat(void)
{
	t_push_swap		*push;
	int				size;
	// int			i;

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

int		the_choosen_alg(t_push_swap *push)
{
	// t_list	*
	int		size;

	(void)push;
	size = push->size_a;
	int i;

	i = 0;
	repeat();
	return (1);
}
