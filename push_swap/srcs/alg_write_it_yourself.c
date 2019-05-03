/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_write_it_yourself.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:25:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/03 13:40:43 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		execute_order_66(t_push_swap *push)
{
	int		r_val;

	if (push->instruction[0] == ' ')
		ft_memmove(push->instruction, &push->instruction[1], ft_strlen(push->instruction));
	r_val = 0;
	if (!ft_strcmp(push->instruction, "sa"))
		r_val = execute_swap(&push->stack_a);
	else if (!ft_strcmp(push->instruction, "sb"))
		r_val = execute_swap(&push->stack_b);
	else if (!ft_strcmp(push->instruction, "ss"))
		r_val = execute_double(push, 0);

	else if (!ft_strcmp(push->instruction, "pa"))
		r_val = extra_push(push, 1);
	else if (!ft_strcmp(push->instruction, "pb"))
		r_val = extra_push(push, 0);

	else if (!ft_strcmp(push->instruction, "ra"))
		r_val = execute_rotation(&push->stack_a, 0);
	else if (!ft_strcmp(push->instruction, "rb"))
		r_val = execute_rotation(&push->stack_b, 0);
	else if (!ft_strcmp(push->instruction, "rr"))
		r_val = execute_double(push, 1);

	else if (!ft_strcmp(push->instruction, "rra"))
		r_val = execute_rotation(&(push->stack_a), 2);
	else if (!ft_strcmp(push->instruction, "rrb"))
		r_val = execute_rotation(&push->stack_b, 2);
	else if (!ft_strcmp(push->instruction, "rrr"))
		r_val = execute_double(push, 2);
	else if (!ft_strcmp(push->instruction, "cs"))
			CLEAR_SCREEN
	else
		return (1);
	return(r_val);
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
