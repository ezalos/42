/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:27:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/02 17:42:46 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

static void		print_menu(void)
{
	C_ORANGE
	ft_putendl("");
	ft_putstr("\t0  : L'ELU\n");
	ft_putstr("\t1  : WRITE\n");
	ft_putstr("\t2  : WRITE EVERYTHING\n");
	ft_putstr("\t3  : BUBBLE\n");
	C_BLUE
	ft_putstr("\tPlease enter your selection :\t");
	C_RESET
}

static int		choose_solve(int choice)
{
	t_push_swap		*push;

	push = (*ft_remember_push());
	if (choice == 0)
		the_choosen_alg(push);
	else if (choice == 1)
		do_it_yourself();//work
	else if (choice == 2)
		write_it_yourself(*ft_remember_push());//work
	else if (choice == 3)
		bubble_it();//work
	print_push_swap(push);
	return (0);
}

int		lets_solve(t_push_swap *push)
{
	char			*instructions;
	int				choice;

	*ft_remember_push() = push;
	if (PROGRESS)
		ft_progress("Init", 3, 3);
	if (VISUAL_MODE)
		print_push_swap(push);
	if (CHOOSE_ALG && VISUAL_MODE)
	{
		print_menu();
		C_CYAN
		if (-1 == get_next_line(0, &instructions))
			return (-1);
		C_RESET
		CLEAR_SCREEN
		choice = ft_atoi(instructions);
		ft_strdel(&instructions);
	}
	else
		choice = 0;
	choose_solve(choice);
	return (push->count);
}
