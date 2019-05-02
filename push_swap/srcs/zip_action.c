/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zip_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:56:51 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/02 17:45:21 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static int		ft_tab_change_two(t_tab *act, char *action)
{
	t_tab	*tab;
	t_tab	*del;
	char	*lec;

	tab = (*ft_remember_push())->actions;
	del = ft_tab_cutone(act->dir[0]);
	ft_memdel((void**)&del);
	del = ft_tab_cutone(act->dir[0]);
	ft_memdel((void**)&del);
	(*ft_remember_push())->count--;
	(*ft_remember_push())->count--;
	(*ft_remember_push())->save += 2;
	if (!action)
		return (1);
	(*ft_remember_push())->save--;
	lec = ft_strdup(action);
	ft_tabadd_here(act, ft_tabnew_ptr(&lec, sizeof(char**)), 0);
	(*ft_remember_push())->count++;
	return (0);
}

static void	ft_recognize_case(t_tab *action)
{
	if (!ft_strcmp(*(char**)action->dir[0]->content, "sa"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "sa"))
			ft_tab_change_two(action, NULL);
		else if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "sb"))
			ft_tab_change_two(action, "ss");
	}
	else if (!ft_strcmp(*(char**)action->dir[0]->content, "sb"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "sb"))
			ft_tab_change_two(action, NULL);
		else if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "sa"))
			ft_tab_change_two(action, "ss");
	}
	else if (!ft_strcmp(*(char**)action->dir[0]->content, "pa"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "pb"))
			ft_tab_change_two(action, NULL);
	}
	else if (!ft_strcmp(*(char**)action->dir[0]->content, "pb"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "pa"))
			ft_tab_change_two(action, NULL);
	}
	else if (!ft_strcmp(*(char**)action->dir[0]->content, "ra"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "rra"))
			ft_tab_change_two(action, NULL);
		else if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "rb"))
			ft_tab_change_two(action, "rr");
	}
	else if (!ft_strcmp(*(char**)action->dir[0]->content, "rb"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "rrb"))
			ft_tab_change_two(action, NULL);
		else if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "ra"))
			ft_tab_change_two(action, "rr");
	}
	else if (!ft_strcmp(*(char**)action->dir[0]->content, "rra"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "ra"))
			ft_tab_change_two(action, NULL);
		else if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "rrb"))
			ft_tab_change_two(action, "rrr");
	}
	else if (!ft_strcmp(*(char**)action->dir[0]->content, "rrb"))
	{
		if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "rb"))
			ft_tab_change_two(action, NULL);
		else if (!ft_strcmp(*(char**)action->dir[0]->dir[0]->content, "rra"))
			ft_tab_change_two(action, "rrr");
	}
}

static void	ft_update_placement(t_tab **action, int *i, int save)
{
	if (save == (*ft_remember_push())->save)
	{
		(*action) = (*action)->dir[0];
		(*i)++;
	}
	else if (*i)
	{
		(*action) = (*action)->dir[2];
		(*i)--;
	}
}

int		traduction(void)
{
	time_exe(__func__);
	t_tab	*action;
	int		i;
	int		save;

	i = 0;
	action = (*ft_remember_push())->actions;
	while (action && action->dir[0] && action->dir[0]->dir[0])
	{
		save = (*ft_remember_push())->save;
		if (PROGRESS)
			ft_progress(__func__, i, (*ft_remember_push())->count);
		ft_recognize_case(action);
		ft_update_placement(&action, &i, save);
	}
	if (PROGRESS)
		ft_progress(__func__, 1, 1);
	return (1);
}
