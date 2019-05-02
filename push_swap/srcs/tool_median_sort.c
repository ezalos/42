/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_median_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:25:09 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/02 17:48:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static int		ft_mv_setup(t_push_swap *push, size_t size, int a, int *median)
{
	time_exe(__func__);
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
	(a) ? (*median = median_a(size)) : (*median = median_b(size));
	return (-1);
}

static int		ft_mv_act(size_t size, int a, int median)
{
	time_exe(__func__);
	int 	i;
	int 	done;

	i = 0;
	done = 0;
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
	return (done);
}

static int		ft_mv_clean(t_push_swap *push, size_t size, int a, int done)
{
	time_exe(__func__);
	int		tip;

	(a) ? (tip = (int)push->size_a) : (tip = (int)push->size_b);
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

int			ft_mv(t_push_swap *push, size_t size, int a)
{
	time_exe(__func__);
	int 	done;
	int 	r_v;
	int		median;

	if ((r_v = ft_mv_setup(push, size, a, &median)) != -1)
		return (r_v);
	done = ft_mv_act(size, a, median);
	return (ft_mv_clean(push, size, a, done));
}
