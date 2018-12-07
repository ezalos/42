/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:04:12 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/07 18:18:57 by ldevelle         ###   ########.fr       */
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
	int		v_return;

	if (ac != 2)
		return (0);
	while (1 == (v_return = get_next_line(open_file((const char *)av[1]), &my_line))) //La valeur de retour peut être 1, 0 ou -1 selon qu’une ligne a été lue, que la lecture est terminée ou bien qu’une erreur est survenue respectivement.
	{
//		ft_putnbr(v_return);
//		ft_putchar('\n');
//		ft_putendl(my_line);
		printf("INSIDE my_line: %s\n", my_line);
	}
	printf("END\tmy_line: %s\n", my_line);
	return (0);
}
