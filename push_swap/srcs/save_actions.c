/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:56:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/10 20:49:05 by ldevelle         ###   ########.fr       */
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

int		ft_tab_change_two(int i, char *action)
{
	t_tab	*tab;
	t_tab	*new;
	char	*lec;

	tab = (*ft_remember_push())->actions;
	ft_tab_cutone(ft_tab_dirth(tab, 0, i));
	ft_tab_cutone(ft_tab_dirth(tab, 0, i));
	(*ft_remember_push())->count--;
	(*ft_remember_push())->count--;
	if (!action)
		return (1);
	lec = ft_strdup(action);
	new = ft_tabnew_ptr(&lec, sizeof(char**));
	ft_tabadd_here(ft_tab_dirth(tab, 0, i - 1),
	ft_tabnew_ptr((char**)cnalloc(&lec, sizeof(char*)), sizeof(char**)), 0);
	(*ft_remember_push())->count++;
	return (0);
}

int		traduction(void)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	// ft_printf("%s\n", __func__);
	while (++i < (*ft_remember_push())->count)
	{
		// ft_printf("%d ", i);
		if (compare_actions("sa", "sb", i))
		{
			ft_tab_change_two(i, "ss");
			i += -3;
			r++;
		}
		else if (compare_actions("sa", "sa", i))
		{
			ft_tab_change_two(i, NULL);
			i += -3;
			r++;
		}
		else if (compare_actions("sb", "sb", i))
		{
			ft_tab_change_two(i, NULL);
			i += -3;
			r++;
		}
		else if (compare_actions("pa", "pb", i))
		{
			ft_tab_change_two(i, NULL);
			i += -3;
			r++;
		}
		else if (compare_actions("ra", "rb", i))
		{
			ft_tab_change_two(i, "rr");
			i += -3;
			r++;
		}
		else if (compare_actions("rra", "rrb", i))
		{
			ft_tab_change_two(i, "rrr");
			i += -3;
			r++;
		}
		else if (compare_actions("ra", "rra", i))
		{
			ft_tab_change_two(i, NULL);
			i += -3;
			r++;
		}
		else if (compare_actions("rb", "rrb", i))
		{
			ft_tab_change_two(i, NULL);
			i += -3;
			r++;
		}
		if (i < 0)
			i = 0;
		// if (i == (*ft_remember_push())->count - 1)
		// {
		// 	if (!r)
		// 		break ;
		// 	else
		// 	{
		// 		ft_printf("\nHELLO\n\n%d\n", r);
		// 		i = 0;
		// 		r = 0;
		// 	}
		// }
	}
	// ft_printf("\n%d\n", r);
	return (1);
}

int		add_action(char *str)
{
	t_tab	*actions;
	t_tab	*new;
	char	*lec;

	if (!str)
		return (-1);
	actions = (*ft_remember_push())->actions;
	lec = ft_strdup(str);
	new = ft_tabnew_ptr(&lec, sizeof(char**));
	if (!(*ft_remember_push())->actions)
		(*ft_remember_push())->actions = ft_tabnew_ptr((char**)cnalloc(&lec, sizeof(char*)), sizeof(char**));
	else
		ft_tabadd_end((*ft_remember_push())->actions, ft_tabnew_ptr((char**)cnalloc(&lec, sizeof(char*)), sizeof(char**)), 0);
	(*ft_remember_push())->count++;
	return (0);
}
