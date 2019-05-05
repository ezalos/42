/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_write_it_yourself.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:25:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 17:55:47 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		execute_order_66(t_push_swap *push)
{
	if (!ft_strcmp(push->instruction, "sa"))
		return (execute_swap(&push->stack_a));
	else if (!ft_strcmp(push->instruction, "sb"))
		return (execute_swap(&push->stack_b));
	else if (!ft_strcmp(push->instruction, "ss"))
		return (execute_double(push, 0));
	else if (!ft_strcmp(push->instruction, "pa"))
		return (extra_push(push, 1));
	else if (!ft_strcmp(push->instruction, "pb"))
		return (extra_push(push, 0));
	else if (!ft_strcmp(push->instruction, "ra"))
		return (execute_rotation(&push->stack_a, 0));
	else if (!ft_strcmp(push->instruction, "rb"))
		return (execute_rotation(&push->stack_b, 0));
	else if (!ft_strcmp(push->instruction, "rr"))
		return (execute_double(push, 1));
	else if (!ft_strcmp(push->instruction, "rra"))
		return (execute_rotation(&(push->stack_a), 2));
	else if (!ft_strcmp(push->instruction, "rrb"))
		return (execute_rotation(&push->stack_b, 2));
	else if (!ft_strcmp(push->instruction, "rrr"))
		return (execute_double(push, 2));
	return (0);
}

int		write_it_yourself(t_push_swap *push)
{
	print_push_swap(push);
	if (0 >= get_next_line(0, &push->instruction))
		return (-1);
	while (push->instruction[0] != '\0')
	{
		if (!(execute_order_66(push)))
			return (-1);
		push->count++;
		print_push_swap(push);
		ft_strdel(&push->instruction);
		if (0 >= get_next_line(0, &push->instruction))
			return (-1);
	}
	return (push->count);
}
