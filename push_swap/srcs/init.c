/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:56:40 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/02 18:25:37 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static int	scrap_ac(t_push_swap *push, int ac, char **av)
{
	int				i;
	int				j;

	i = -1;
	while (++i < ac)
	{
		if (PROGRESS)
			ft_progress(__func__, i, ac - 1);
		j = -1;
		while (av[i + 1][++j])
			if (!ft_isdigit(av[i + 1][j]))
				return (0);
		j = ft_atoi(av[i + 1]);
		if (!push->stack_a)
			push->stack_a = ft_tabnew_ptr((int*)cnalloc(&j, sizeof(int)),
			sizeof(int*));
		else
			ft_tabadd_end(push->stack_a, ft_tabnew_ptr((int*)cnalloc(&j,
			sizeof(int)), sizeof(int*)), 0);
	}
	return (1);
}

t_push_swap	*setup_tab(int ac, char **av)
{
	t_push_swap		*push;

	push = (t_push_swap*)cnalloc(NULL, sizeof(t_push_swap));
	push->all = ac;
	push->size_a = push->all;
	push->stack_b = NULL;
	if (!scrap_ac(push, ac, av))
		return (NULL);
	ft_tabloop_it(push->stack_a, 0);
	*ft_remember_push() = push;
	return (push);
}
