/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:28:03 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/10 22:56:10 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	print_it(t_tab *stack)
{
	int		i;
	int		col;

	i = -1;
	col = 0;
	if ((*ft_remember_push())->count > 66)
		col = 15 * 3;
	C_RESET
	while (++i <= 5 + (int)(*ft_remember_push())->size_b)
		ft_tab_print_one_elmnt(ft_tab_dirth(stack, 0, i), 24 + (i * 5), col, *(int*)ft_tab_dirth(stack, 0, i)->content);
}

int		ft_mv(t_push_swap *push, size_t size, int a)
{
	int 	i;
	int 	done;
	int		median;
	int		tip;

	if (!size)
		return (0);
	if ((a && (size > push->size_a)) || (!a && (size > push->size_b)))
		return (0);
	if (size == 1)
	{
		if (a)
			pa();
		else
			pb();
		return (1);
	}
	i = 0;
	done = 0;
	if (a)
		median = median_a(size);
	else
		median = median_b(size);
	while (i < (int)size && (i - done) * 2 < (int)size)
	{
		if (a)
		{
			if (stack_a(0) <= median)
				pa();
			else
			{
				ra();
				done++;
			}
		}
		else
			if (stack_b(0) > median)
				pb();
			else
			{
				rb();
				done++;
			}
		i++;
	}
	if (a)
		tip = (int)push->size_a;
	else
		tip = (int)push->size_b;
	if (done == tip)
		return (size / 2);
	else if (done < tip - done)
	{
		while (done--)
			if (a)
				rra();
			else
				rrb();
	}
	else
	{
		while (tip - 1 > done++)
			if (a)
				ra();
			else
				rb();
	}
	return (size / 2);
}
