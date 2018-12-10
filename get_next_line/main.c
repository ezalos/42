/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:04:12 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/10 22:19:14 by ldevelle         ###   ########.fr       */
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
	int		fd[10];
	int		v_return;
	int		turn;

	if (ac >= 9)
		return (0);
	loop = 0;
	while (++loop < ac)
		fd[loop - 1] = open_file((const char *)av[loop]);
	loop = 0;
	while (0 <= (v_return = get_next_line(fd[loop], &my_line)))
	{
		printf("%d line\t|\tr_val:%d\n%s\n\n\n", loop, v_return, my_line);
		if (v_return == 0)
			fd[loop] = 0;
		turn = 0;
		while (fd[++loop] == 0)
		{
			if (loop >= ac - 2)
			{
				if (turn == 1)
					return (0);
				loop = 0;
				turn = 1;
			}
		}
	}
	return (0);
}
