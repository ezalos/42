/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_perfect_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:29:58 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/05 17:25:02 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static void	ab_2(void)
{
	if (stack_a(0) >= stack_a(1))
		sa();
}

static int	perfect_ab(size_t size)
{
	if (size == 0 || size == 1)
		return (-1);
	else if (size == 2)
		ab_2();
	else if (size == 3)
		ab_3();
	time_exe(__func__);
	return (-1);
}

int			ab(size_t size)
{
	int		r_v;

	(*ft_sent_count()) = 0;
	if (size < 4)
	{
		r_v = perfect_ab(size);
		if (VISUAL_MODE == 1)
			print_push_swap((*ft_remember_push()));
		return ((*ft_sent_count()));
	}
	r_v = ft_mv(*ft_remember_push(), size, 1);
	if (VISUAL_MODE == 1)
		print_push_swap((*ft_remember_push()));
	return ((*ft_sent_count()));
}
