/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:04:12 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/10 17:12:36 by ldevelle         ###   ########.fr       */
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
	int		fd;
	int		v_return;

	if (ac != 2)
		return (0);
	loop = -1;
	fd = open_file((const char *)av[1]);
	while (1 == (v_return = get_next_line(fd, &my_line)) && ++loop < 10) //La valeur de retour peut être 1, 0 ou -1 selon qu’une ligne a été lue, que la lecture est terminée ou bien qu’une erreur est survenue respectivement.
	{
		printf("INSIDE\tmy_line:%s\n\t\treturn value %d", my_line, v_return);
		printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	}
	printf("\nEND\tmy_line:%s\n", my_line);
	return (0);
}
