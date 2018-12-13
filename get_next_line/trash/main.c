/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:04:12 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/12 17:56:45 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

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
	loop = -1;
	while (++loop < ac - 1)
	{
		fd[loop][0] = open_file((const char *)av[loop + 1]);
		fd[loop][1] = 0;
		printf(_RED "WE SAVED A NEW FILE DESCRITOR %s : %d\t\t(loop%d)\n" _RESET, av[loop + 1], fd[loop][0], loop);
	}
	loop = 0;
	printf(_RED "\n\nWE NOW ARE STARTING %s\nFD:%d ON LINE : %d\t(loop%d)\n" _RESET, av[loop + 1], fd[loop][0], fd[loop][1], loop);
	while (0 <= (v_return = get_next_line(fd[loop][0], &my_line)))
	{
		fd[loop][1]++;
		printf(_RED "%s->line %d\t|\tr_val:%d\n|-->%s|\n\n" _RESET, av[loop + 1], fd[loop][1], v_return, my_line);
		printf("strcmp : %d\n", ft_strcmp(my_line, "1234567"));
		printf("############################################################\n\n");
		ft_bzero(my_line, ft_strlen(my_line));
		if (v_return == 0)
			fd[loop][0] = 0;
		turn = 0;
		printf(_RED  "loop >= ac - 2 ? %d > %d\n" _RESET, loop, ac - 2);
		if (loop >= ac - 2)
		{
			loop = -1;
			printf(_RED  "loop = %d\n" _RESET, loop);
		}
		while (fd[++loop][0] == 0)
		{
			printf(_RED  "fd[%d][0]==0\n" _RESET, loop);
			if (loop >= ac - 2)
			{
				loop = -1;
				if (turn == 1)
					return (0);
				turn = 1;
			}
		}
		printf(_RED  "ac:%d\n" _RESET,  ac);
		printf(_RED "\nWE NOW ARE STARTING %s\nFD:%d ON LINE : %d\t(loop%d)\n" _RESET, av[loop + 1], fd[loop][0], fd[loop][1], loop);
	}
	if (v_return == -1)
		{
			printf(_RED "ERROR: function returned -1\nQUITTING\n" _RESET);
			return (-1);
		}
	return (0);
}
