/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:15:02 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/30 12:09:15 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

t_push_swap		**ft_remember_push(void)
{
	static t_push_swap		*push;

	return (&push);
}

void			pa(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (extra_push(push, 1))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
	// ft_strdel(&push->instruction);
	// push->count++;
}

void			pb(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (extra_push(push, 0))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
	// ft_strdel(&push->instruction);
	// push->count++;
}

void			sa(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_swap(&push->stack_a))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
	// ft_strdel(&push->instruction);
	// push->count++;
}

void			sb(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_swap(&push->stack_b))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
	// ft_strdel(&push->instruction);
	// push->count++;
}

void			ra(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_rotation(&push->stack_a, 0))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
	// ft_strdel(&push->instruction);
	// push->count++;
}

void			rra(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_rotation(&(push->stack_a), 2))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
	// push->count++;
}

void			rb(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_rotation(&push->stack_b, 0))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
	// push->count++;
}

void			rrb(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_rotation(&push->stack_b, 2))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
	// push->count++;
}

void			rr(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_double(push, 1))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
	// push->count++;
}

void			rrr(void)
{
	t_push_swap		*push;

	push = *ft_remember_push();
	push->instruction = ft_strdup(__func__);
	if (execute_double(push, 2))
		add_action(push->instruction);
	else
		ft_strdel(&push->instruction);
	// push->count++;
}
