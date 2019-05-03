/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_insertion_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:10:07 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/03 16:30:42 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int					ft_find_biggest_b(int size)
{
	int				i;
	int				winner;

	// ft_printf("%s\n", __func__);
	if (size > (int)(*ft_remember_push())->size_b)
		size = (*ft_remember_push())->size_b;
	i = 0;
	winner = 0;
	while (++i < size)
		if (stack_b(i) > stack_b(winner))
			winner = i;
	return (winner);
}

int					go_to_a_th(int access)
{
	int				moved;
	int				neg;

	moved = 0;
	neg = 0;
	if (access < 0)
	{
		access = -access;
		neg = 1;
	}
	if ((*ft_remember_push())->size_a)
		access = access % (int)(*ft_remember_push())->size_a;
	else
		return (0);
	if ((access <= (int)(*ft_remember_push())->size_a / 2 && !neg)
	|| (access >= (int)(*ft_remember_push())->size_a / 2 && neg))
		while (moved < access)
		{
			ra();
			moved++;
		}
	else
		while (-moved < access)
		{
			rra();
			moved--;
		}
	return (moved);
}

int					go_to_b_th(int access)
{
	int				moved;
	int				neg;

	// ft_printf("%s\n", __func__);
	moved = 0;
	neg = 0;
	if (access < 0)
	{
		access = -access;
		neg = 1;
	}
	access = access % (int)(*ft_remember_push())->size_b;
	if ((access <= (int)(*ft_remember_push())->size_b / 2 && !neg)
	|| (access >= (int)(*ft_remember_push())->size_b / 2 && neg))
		while (moved < access)
		{
			rb();
			moved++;
		}
	else
		while (-moved < access)
		{
			rrb();
			moved--;
		}
	return (moved);
}

int					ft_insert_push_ba(int size)
{
	int				focus;
	int				moved;

	if (size > (int)(*ft_remember_push())->size_b)
		size = (*ft_remember_push())->size_b;
	moved = 0;
	while (size)
	{
		// ft_printf("%s\n", __func__);
		focus = ft_find_biggest_b(size);
		moved = focus;
		// ft_printf("%s\n", "focus");
		while (focus--)
			rb();
		//moved = go_to_b_th(focus);
		pb();
		// ft_printf("%s\n", "moved");
		if (moved)
			while (moved--)
				rrb();
		//go_to_b_th(-moved);
		// ft_printf("SIZE IS : %d\n", size);
		print_push_swap((*ft_remember_push()));
		size--;
	}
	return (1);
}
