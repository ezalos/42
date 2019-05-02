/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:04:27 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/02 14:20:17 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		order_a(int size)
{
	int			i;
	int			actual;
	int			save;
	t_push_swap	*push;

	i = -1;
	push = *ft_remember_push();
	if (size > (int)push->size_a)
		size = (int)push->size_a;
	while (++i < size)
	{
		actual = *(int*)ft_tab_dirth(push->stack_a, 0, i)->content;
		if (i && save > actual)
			return (0);
		save = actual;
	}
	return (1);
}

int		order_b(int size)
{
	int			i;
	int			actual;
	int			save;
	t_push_swap	*push;

	i = -1;
	push = *ft_remember_push();
	if (size > (int)push->size_b)
		size = (int)push->size_b;
	while (++i < size)
	{
		actual = *(int*)ft_tab_dirth(push->stack_b, 0, i)->content;
		if (i && save > actual)
			return (0);
		save = actual;
	}
	return (1);
}

int		ft_get_median(t_tab *stack, size_t size)
{
	int *squick;
	int i;

	squick = ft_memalloc(sizeof(int) * (size));
	i = -1;
	while (++i < (int)size)
		squick[i] = *(int*)ft_tab_dirth(stack, 0, i)->content;
	i = -1;
	ft_squick_sort(&squick, 0, size - 1);
	if (size)
		i = squick[(size - 1) / 2];
	else
		return (-1);
	ft_memdel((void**)&squick);
	return (i);
}

int		median_a(size_t size)
{
	return (ft_get_median((*ft_remember_push())->stack_a, size));
}

int		median_b(size_t size)
{
	return (ft_get_median((*ft_remember_push())->stack_b, size));
}

int			stack_a(int i)
{
	time_exe(__func__);
	t_tab		*stack;
	int			r_v;

	stack = (*ft_remember_push())->stack_a;
	r_v = *(int*)ft_tab_dirth(stack, 0, i)->content;
	time_exe("END");
	return (r_v);
}

int			stack_b(int i)
{
	time_exe(__func__);
	t_tab		*stack;

	stack = (*ft_remember_push())->stack_b;
	return (*(int*)ft_tab_dirth(stack, 0, i)->content);
}

int		ab(size_t size)
{
	int		r_v;

	if (size <= 4)
	{
		r_v = perfect_ab(size);
		if (VISUAL_MODE == 1)
			print_push_swap((*ft_remember_push()));
		return (r_v);
	}
	r_v = ft_mv(*ft_remember_push(), size, 1);
	if (VISUAL_MODE == 1)
		print_push_swap((*ft_remember_push()));
	return (r_v);
}

int		ba(size_t size)
{
	int		r_v;

	if (size == 0)
		return (0);
	if (size == 1)
	{
		pb();
		if (VISUAL_MODE == 1)
			print_push_swap((*ft_remember_push()));
		return (1);
	}
	if (size == 2)
	{
		if (stack_b(0) < stack_b(1))
			sb();
		pb();
		if (VISUAL_MODE == 1)
			print_push_swap((*ft_remember_push()));
		return (1);
	}
	if (size == 3)
	{
		ba_3();
		return (1);
	}
	r_v = ft_mv(*ft_remember_push(), size, 0);
	if (VISUAL_MODE == 1)
		print_push_swap((*ft_remember_push()));
	return (r_v);
}
