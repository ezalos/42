/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:56:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/01 19:32:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

char	*action_nb(int i)
{
	return (*(char**)
	ft_tab_dirth((*ft_remember_push())->actions, 0, i)->content);
}

int		compare_actions(char *one, char *two, int i)
{
	if ((!ft_strcmp(action_nb(i), one) && !ft_strcmp(action_nb(i + 1), two))
	|| ((!ft_strcmp(action_nb(i), two) && !ft_strcmp(action_nb(i + 1), one))))
	{
		// ft_printf("[%d]:%s && [%d]:%s\n", i, action_nb(i), i + 1, action_nb(i + 1));
		return (1);
	}
	return (0);
}

int		ft_tab_change_two(t_tab *act, char *action)
{
	t_tab	*tab;
	t_tab	*del;
	char	*lec;

	// ft_printf("{%s}", action);
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

int		traduction(void)
{
	time_exe(__func__);
	t_tab	*action;
	int		i;
	int		save;

	i = 0;
	// ft_printf("%s\n", __func__);if (PROGRESS)
	action = (*ft_remember_push())->actions;
	while (action && action->dir[0] && action->dir[0]->dir[0])
	{
		// ft_printf("%d ", i);
		save = (*ft_remember_push())->save;
		if (PROGRESS)
			ft_progress(__func__, i, (*ft_remember_push())->count);
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
		if (save == (*ft_remember_push())->save)
		{
			action = action->dir[0];
			i++;
		}
		else if (i)
		{
			action = action->dir[2];
			i--;
		}
		// if (i > 970)
		// {
		// 	ft_printf("%-*d ", 5, i);
		// 	ft_print_address_color((intmax_t)action);
		// 	ft_print_address_color((intmax_t)action->dir[0]);
		// 	ft_print_address_color((intmax_t)action->dir[0]->dir[0]);
		// 	ft_print_address_color((intmax_t)action->dir[0]->dir[0]->dir[0]);
		// 	ft_printf("\n");
		// }
	}
	if (PROGRESS)
	{
		ft_progress(__func__, (*ft_remember_push())->count, (*ft_remember_push())->count);
	}
	return (1);
}

int		add_action(char *str)
{
	time_exe(__func__);
	t_tab	*actions;
	char	*lec;

	if (!str)
		return (-1);
	actions = (*ft_remember_push())->actions;
	lec = str;
	if (!(*ft_remember_push())->actions)
		(*ft_remember_push())->actions = ft_tabnew_ptr(&lec, sizeof(char**));
	else
		ft_tabadd_end((*ft_remember_push())->actions, ft_tabnew_ptr(&lec, sizeof(char**)), 0);
	(*ft_remember_push())->count++;
	if (VISUAL_MODE == 2)
		print_push_swap((*ft_remember_push()));
	time_exe("__func__");
	return (0);
}
