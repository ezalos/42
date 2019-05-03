/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_stack_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:25:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/03 15:29:50 by ldevelle         ###   ########.fr       */
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

int			stack_a(int i)
{
	time_exe(__func__);
	t_tab		*stack;
	int			r_v;

	if (!(*ft_remember_push())->stack_a)
		return (-1);
	stack = (*ft_remember_push())->stack_a;
	r_v = *(int*)ft_tab_dirth(stack, 0, i)->content;
	time_exe("END");
	return (r_v);
}

int			stack_b(int i)
{
	time_exe(__func__);
	t_tab		*stack;

	if (!(*ft_remember_push())->stack_b)
		return (-1);
	stack = (*ft_remember_push())->stack_b;
	return (*(int*)ft_tab_dirth(stack, 0, i)->content);
}
