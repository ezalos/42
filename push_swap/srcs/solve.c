/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:27:41 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/30 18:31:20 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		do_it_yourself(void)
{
	t_push_swap		*push;
	char			*line;
	int				nb;

	push = *ft_remember_push();
	print_push_swap(push);
	ft_putstr("exe:");
	if (0 >= get_next_line(0, &line))
		return (-1);
	while (line[0] != '\0')
	{
		if (line[1] != '\0')
			nb = ft_atoi(line + 1);
		else
			if (line[0] == 'a')
				nb = push->size_a;
			else
				nb = push->size_b;
		ft_printf("  %d   ", nb);
		if (line[0] == 'a')
			ab(nb);
		else
			ba(nb);
		print_push_swap(push);
		ft_strdel(&line);
		ft_putstr("exe:");
		if (0 >= get_next_line(0, &line))
			return (-1);
	}
	if (push->size_b == 1)
		pb();
	return (push->count);
}

void		print_menu(void)
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

int		choose_solve(void)
{
	char			*instructions;
	int				choice;
	t_push_swap		*push;

	push = (*ft_remember_push());

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
	}
	else
 		choice = 0;
	if (choice == 0)
		the_choosen_alg(push);
	else if (choice == 1)
		do_it_yourself();//work
	else if (choice == 2)
		lets_play(*ft_remember_push());//work
	else if (choice == 3)
		bubble_it();//work
	ft_strdel(&instructions);
	print_push_swap(push);
	return (0);
}

int		lets_solve(t_push_swap *push)
{
	// char			*line;

	*ft_remember_push() = push;
	choose_solve();
	return (push->count);
}