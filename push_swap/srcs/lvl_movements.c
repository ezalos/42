/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:53:07 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 16:05:19 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		execute_double(t_push_swap *push, int mode)
{
	int		r_val;

	r_val = 0;
	if (mode == 0)
	{
		r_val += execute_swap(&push->stack_a);
		r_val += execute_swap(&push->stack_b);
	}
	if (mode == 1)
	{
		r_val += execute_rotation(&push->stack_a, 0);
		r_val += execute_rotation(&push->stack_b, 0);
	}
	if (mode == 2)
	{
		r_val += execute_rotation(&push->stack_a, 2);
		r_val += execute_rotation(&push->stack_b, 2);
	}
	return (r_val);
}

int		extra_push(t_push_swap *push, int a)
{
	if (a)
	{
		if (push->size_a)
			if (execute_push(&push->stack_a, &push->stack_b))
			{
				push->size_a--;
				push->size_b++;
				return (1);
			}
	}
	else
	{
		if (push->size_b)
			if (execute_push(&push->stack_b, &push->stack_a))
			{
				push->size_a++;
				push->size_b--;
				return (1);
			}
	}
	return (0);
}
