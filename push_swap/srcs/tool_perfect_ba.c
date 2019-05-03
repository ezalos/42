/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_perfect_ba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:40:11 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/03 18:46:25 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static void	ba_3(void)
{
	time_exe(__func__);
	int		a;
	int		b;
	int		c;

	a = stack_b(0);
	b = stack_b(1);
	c = stack_b(2);
	if (a > b)
	{
		if (b > c && a > c)		//012 210
		{
			pb();
			pb();
			pb();
		}
		else if (c > b && a > c)//021 201	put c first
		{
			pb();
			sb();
			pb();
			pb();
		}
		else					//120 102	switch b & c
		{
			rb();
			sb();
			pb();
			rrb();
			pb();
			pb();
		}
	}
	else if (a < b)
	{
		if (b < c && a < c)		//210 012	switch a & c
		{
			rb();
			sb();
			pb();
			pb();
			rrb();
			pb();
		}
		else if (a < c && a < c)	//201 021	put a last
		{
			sb();
			pb();
			sb();
			pb();
			pb();
		}
		else			//102 120	switch a & b
		{
			sb();
			pb();
			pb();
			pb();
		}

	}
}

int		ba(size_t size)
{
	int		r_v;

	r_v = 1;
	if (size == 0)
		return (0);
	else if (size == 1)
		pb();
	else if (size == 2)
	{
		if (stack_b(0) < stack_b(1))
			sb();
		pb();
	}
	// else if (size == 3)
	// 	ba_3();
	// else if (size <= 8)
	// 	ft_insert_push_ba(size / 2);
	else
		r_v = ft_mv(*ft_remember_push(), size, 0);
	if (VISUAL_MODE == 1)
		print_push_swap((*ft_remember_push()));
	return (r_v);
}
