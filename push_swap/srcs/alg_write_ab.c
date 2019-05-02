/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_write_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:32:07 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/02 17:32:16 by ldevelle         ###   ########.fr       */
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
