/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:37:14 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/12 20:34:06 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		main(int ac, char **av)
{
	char	reader[10000];
	int		file_descriptor;
	int		i;

	if (ac < 2)
		ft_error("File name missing.\n");
	else if (ac > 2)
		ft_error("Too many arguments.\n");
	else
	{
		i = 0;
		while (i < 9999)
			reader[i++] = 0;
		if (!(file_descriptor = ft_open(av[1])))
			return (0);
		if (!ft_read(file_descriptor, reader))
			return (0);
		ft_putstr(reader);
		ft_putchar('\n');
		if (-1 == close(file_descriptor))
			return (ft_error("Error while closing the file\n"));
	}
	return (0);
}
