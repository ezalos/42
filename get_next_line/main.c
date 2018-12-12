/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:04:12 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/11 18:49:52 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		open_file(const char *pathname)
{
	return (open(pathname, O_RDONLY));
}

int		main(int ac, char **av)
{
	char	*my_line = NULL;
	int		loop;
	int		fd[10][2];
	int		v_return;
	int		turn;

	if (ac >= 9)
		return (0);
	loop = 0;
	while (++loop < ac)
	{
		fd[loop - 1][0] = open_file((const char *)av[loop]);
		fd[loop - 1][1] = 0;
	}
	loop = 0;
	printf("WE NOW ARE STARTING %s\n", av[loop + 1]);
	while (0 <= (v_return = get_next_line(fd[loop][0], &my_line)))
	{
		fd[loop][1]++;
		printf("%s->line %d\t|\tr_val:%d\n%s|\n\n\n", av[loop], fd[loop][1], v_return, my_line);
		if (v_return == 0)
			fd[loop][0] = 0;
		turn = 0;
		while (fd[++loop][0] == 0)
		{
			if (loop >= ac - 2)
			{
				if (turn == 1)
					return (0);
				loop = 0;
				turn = 1;
			}
		}
		printf("WE NOW ARE STARTING %s ON LINE %d\t (loop : %d)\n", av[loop], fd[loop][1], loop);
	}
	return (0);
}
