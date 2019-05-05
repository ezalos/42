/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_insertion_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:10:07 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 15:11:46 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int					ft_find_biggest_b(int start, int size)
{
	int				i;
	int				winner;

	if (size > (int)(*ft_remember_push())->size_b)
		size = (*ft_remember_push())->size_b;
	i = start;
	winner = start;
	while (++i < size + start)
	{
		// ft_printf("%-3d|RAN%3d\t%-3dWIN|\n", i, stack_b(i), stack_b(winner));
		if (stack_b(i) > stack_b(winner))
			winner = i;
	}
	return (winner);
}

int					ft_find_smallest_a(int start, int size)
{
	int				i;
	int				winner;

	if (size > (int)(*ft_remember_push())->size_a)
		size = (*ft_remember_push())->size_a;
	i = start;
	winner = start;
	while (++i < size + start)
	{
		// ft_printf("%-3d|RAN%3d\t%-3dWIN|\n", i, stack_b(i), stack_b(winner));
		if (stack_a(i) < stack_a(winner))
			winner = i;
	}
	return (winner);
}

int					ft_find_just_under_a(int ref, int start, int size)
{
	int				i;
	int				second;
	int				found;

	if (size > (int)(*ft_remember_push())->size_a)
		size = (*ft_remember_push())->size_a;
	i = start - 1;
	found = 0;
	// ft_printf("%s%d\t%-3d|???%3d\t   WIN|%3d\n", __func__, found, i, stack_a(i), ref);
	while (++i < size + start)
	{
		if (!found && stack_a(i) < ref && ++found)
			second = i;
		if (found && stack_a(i) > stack_a(second) && stack_a(i) < ref)
			second = i;
			// ft_printf("%s%d\t%-3d|???%3d\t%-3dWIN|%3d\n", __func__, found, i, stack_a(i), stack_a(second), ref);
	}
	if (!found)
		return (0);
	return (second + 1);//bc if smaller, needs to go to end of list
}

int					ft_find_just_under_b(int ref, int start, int size)
{
	int				i;
	int				second;
	int				found;

	if (size > (int)(*ft_remember_push())->size_b)
		size = (*ft_remember_push())->size_b;
	i = start - 1;
	found = 0;
	// ft_printf("%~{?}ref%d start%d size%d\n", ref, start, size);
	// ft_printf("%s%d\t%-3d|???%3d\t   WIN|%3d\n", __func__, found, i, stack_b(i), ref);
	while (++i < size + start)
	{
		if (!found && stack_b(i) < ref && ++found)
			second = i;
		if (found && stack_b(i) > stack_b(second) && stack_b(i) < ref)
			second = i;
			// ft_printf("%s%d\t%-3d|???%3d\t%-3dWIN|%3d\n", __func__, found, i, stack_b(i), stack_b(second), ref);
	}
	// if (found)
	// 	ft_printf("found: %d%~{}\n", stack_b(second));
	if (!found)
		return (size * 2);
	return (second);//bc if smaller, needs to go to end of list
}

int					ft_find_just_upper_a(int ref, int start, int size)
{
	int				i;
	int				second;
	int				found;

	if (size > (int)(*ft_remember_push())->size_a)
		size = (*ft_remember_push())->size_a;
	i = start - 1;
	found = 0;
	// ft_printf("%s%d\t%-3d|???%3d\t   WIN|%3d\n", __func__, found, i, stack_a(i), ref);
	while (++i < size + start)
	{
		if (!found && stack_a(i) > ref && ++found)
			second = i;
		if (found && stack_a(i) < stack_a(second) && stack_a(i) > ref)
			second = i;
			// ft_printf("%s%d\t%-3d|???%3d\t%-3dWIN|%3d\n", __func__, found, i, stack_a(i), stack_a(second), ref);
	}
	if (!found)
		return(ft_find_just_under_a(ref, start, size));
	return (second);
}

int					ft_find_second_biggest_b(int start, int size)
{
	int				i;
	int				biggest;
	int				second;

	if (size > (int)(*ft_remember_push())->size_b)
		size = (*ft_remember_push())->size_b;
	i = start;
	biggest = ft_find_biggest_b(start, size);
	second = start;
	while (++i < size + start)
		if (stack_b(i) > stack_b(second) && stack_b(i) < stack_b(biggest))
			second = i;
	return (second);
}

int					go_to_b_th(int access, int on)
{
	int				moved;
	int				neg;

	moved = 0;
	neg = 1;
	if (access < 0 && (access = -access))
		neg = -1;
	if (!(*ft_remember_push())->size_b)
		return (0);
	access = access % (int)(*ft_remember_push())->size_b;
	print_push_swap((*ft_remember_push()));
	// ft_printf("WE MOOOOVE TO %d\n", access);
	if (access <= (int)(*ft_remember_push())->size_b - access)
		while (neg * moved < access)
		{
			if (on)
				neg == 1 ? rb() : rrb();
			moved += neg;
		}
	else
		while (neg * -moved < (int)(*ft_remember_push())->size_b - access)
		{
			if (on)
				neg == -1 ? rb() : rrb();
			moved += -neg;
		}
	if (on)
		print_push_swap((*ft_remember_push()));
	return (moved);
}

int					go_to_a_th(int access, int on)
{
	int				moved;
	int				neg;

	moved = 0;
	neg = 1;
	if (access < 0 && (access = -access))
		neg = -1;
	if (!(*ft_remember_push())->size_a)
		return (0);
	access = access % (int)(*ft_remember_push())->size_a;
	print_push_swap((*ft_remember_push()));
	// ft_printf("WE MOOOOVE TO %d\n", access);
	if (access <= (int)(*ft_remember_push())->size_a - access)
		while (neg * moved < access)
		{
			if (on)
				neg == 1 ? ra() : rra();
			moved += neg;
		}
	else
		while (neg * -moved < (int)(*ft_remember_push())->size_a - access)
		{
			if (on)
				neg == -1 ? ra() : rra();
			moved += -neg;
		}
	if (on)
		print_push_swap((*ft_remember_push()));
	return (moved);
}

int					ft_auto_stoppeur(int *size, int *moved, int *focus)
{
	int				temp;
	int				option;

	// return (0);
	option = ft_find_second_biggest_b(-*moved, *size);
	option = go_to_b_th(option, 0);
	// ft_printf("Second_B[%-3d]=%d\n%~{}", option,stack_b(option));
	if ((0 <= option && option < *focus)
	|| (0 >= option && option > *focus))
	{
		*moved += (temp = go_to_b_th(option, 1));
		*focus -= temp;
		// ft_printf("%~{?}OPTBiggest[%-3d]=%-3d\nOPTSecond_B[%-3d]=%-3d\n%~{}", focus, stack_b(focus), option + temp,stack_b(option + temp));
		pb();
		if (*focus > 0)
			(*focus)--;
		(*size)--;
		option = 1;
		print_push_swap((*ft_remember_push()));
	}
	else
		option = 0;
	return (option);
}

/*
** Every time the value just under ref is found on the way, it is put at the end of A to win actions
*/

/*
** PSEUDO CODE: func
** 					if just_under_b exist
** 					{
** 						ret = func
** 						go_to just_under_b		---> here is the problem, hard to update all the coordinates in recursive
** 						do pb + ra
** 						return (1 + ret)
** 					}
** 					ret (0)
*/

int					*ft_move_update(void)
{
	static int		move_update;

	return (&move_update);
}

int					ft_auto_stoppeurs(int *size, int *moved, int *focus, int *one_late, int ref)
{
	int				temp;
	int				r_v;
	int				option;

	// ft_printf("%s\n", __func__);
	if ((option = ft_find_just_under_b(ref, -(*moved), *size)) > *size)// || (*ft_move_update()) > 5)
		return (0);
	option = go_to_b_th(option, 0);
	if ((one_late && ((0 <= option && option + COST < *one_late) /*|| (0 >= option && option - COST > *one_late)*/))
	|| (!one_late && ((0 <= option && option + COST < *focus) /*|| (0 >= option && option - COST > *focus)*/)))
	{
		// one_late = &option;
		// ft_printf("FOUND[%-3d]=%-3d < %-3d\n%~{}", option, stack_b(option),ref);
		r_v = ft_auto_stoppeurs(size, moved, focus, &option, stack_b(option));
		option -= r_v;
		*moved += (temp = go_to_b_th(option, 1));
		*focus -= temp;
		// ft_printf("%~{?}OPTBiggest[%-3d]=%-3d\nOPTSecond_B[%-3d]=%-3d\n%~{}", focus, stack_b(*focus), option + temp,stack_b(option + temp));
		pb();
		// if (one_late)
			ra();
		(*ft_move_update())++;
		// if (one_late && *focus > 0)
		if (*focus > 0)
			(*focus)--;
		(*size)--;
		print_push_swap((*ft_remember_push()));
		temp += r_v;
		if (one_late && *one_late > 0)
			return (temp + 1);
		else
			return (temp);
	}
	else
		return (0);
}

int					ft_insert_push_ba(int size)
{
	int				focus;
	int				option;
	int				moved;
	int				special;

	if (size > (int)(*ft_remember_push())->size_b)
		size = (*ft_remember_push())->size_b;
	moved = 0;
	while (size)
	{
		// ft_printf("%s\n", __func__);
		// ft_printf("%~{?}SIZE %-3d MOVED %-3d\n%~{}", size, moved);
		focus = ft_find_biggest_b(-moved, size);
		focus = go_to_b_th(focus, 0);
		special = 0;
		// ft_printf("%~{?}Biggest[%-3d]=%d\n", focus, stack_b(focus));
		*ft_move_update() = 0;
		if (OLD)
			option = ft_auto_stoppeur(&size, &moved, &focus);
		else if (focus)
		{
			option = ft_auto_stoppeurs(&size, &moved, &focus, NULL, stack_b(focus));
			if (!option)
				special = ft_auto_stoppeur(&size, &moved, &focus);
		}
		moved += go_to_b_th(focus, 1);
		pb();
		// if (!OLD && (*ft_move_update())--)
		// 	sa();
		while (!OLD && (*ft_move_update())--)
		{
			// if (!(*ft_move_update()))
			// 	sa();
			// else
				rra();
		}
		if ((OLD && option) || special)
			sa();
		print_push_swap((*ft_remember_push()));
		size--;
		if (PROGRESS)
			ft_progress(__func__, (*ft_remember_push())->size_a, (*ft_remember_push())->all);
	}
	return (1);
}

int				ft_real_insertion_sort_b(int size)
{
	int				moved;
	int				act;
	int				sent;

	if (size > (int)(*ft_remember_push())->size_b)
		size = (*ft_remember_push())->size_b;
	moved = 0;
	sent = 0;
	while (size)
	{
		act = 0;
		while (!act)
		{
			// ft_printf("Size %-3d Moved %-3d Sent %-3d\n", size, moved, sent);
			if (stack_a(-1) < stack_b(0) && stack_a(0) > stack_b(0))
				act = 1;
			else if (stack_a(-1) < stack_b(0) && stack_a(0) < stack_b(0))
			{
				if (stack_a(-1) < stack_a(0))
					moved += go_to_a_th(ft_find_just_under_a(stack_b(0), 0, (*ft_remember_push())->size_a), 1);
				else
					act = 1;
			}
			else if (stack_a(-1) > stack_b(0) && stack_a(0) > stack_b(0))
			{
				if (stack_a(-1) < stack_a(0))//is up the list, but might be shorter to go the other way
					moved += go_to_a_th(ft_find_just_upper_a(stack_b(0), 0, (*ft_remember_push())->size_a), 1);
				else
					act = 1;
			}
			else if (stack_a(-1) > stack_b(0) && stack_a(0) < stack_b(0))
				moved += go_to_a_th(ft_find_just_upper_a(stack_b(0), 0, (*ft_remember_push())->size_a), 1);
			print_push_swap((*ft_remember_push()));
		}
		pb();
		sent++;
		print_push_swap((*ft_remember_push()));
		size--;
		if (PROGRESS)
			ft_progress(__func__, (*ft_remember_push())->size_a, (*ft_remember_push())->all);
	}
	// ft_find_biggest_b(-moved, size);
	if (stack_a(-1) < stack_a(0) && stack_a(0) > stack_a(1))
		ra();
	else
		while (stack_a(-1) < stack_a(0))
		{
			moved += go_to_a_th(ft_find_smallest_a(0, (*ft_remember_push())->size_a), 1);
			print_push_swap((*ft_remember_push()));
		}
	return (1);
}

int				ft_secial_insert(int size)
{
	while ((*ft_remember_push())->size_b)
	{
		// ft_printf("\t\t%s size: %d\n", __func__, size);
		ft_insert_push_ba(size);
		size *= 2;
		if (size > (int)(*ft_remember_push())->size_b)
			size = (*ft_remember_push())->size_b;
	}
	return (1);
}
