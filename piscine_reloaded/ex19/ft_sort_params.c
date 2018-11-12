/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:33:30 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/12 17:46:12 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_params(int ac, char **av)
{
	int i;

	i = 0;
	if (ac >= 2)
	{
		while (++i < ac)
		{
			while (*(av[i]))
				ft_putchar(*(av[i]++));
			ft_putchar('\n');
		}
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 || *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	**ft_sort_params(int ac, char **av)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < ac - 1)
		if (0 < ft_strcmp(av[i], av[i + 1]))
		{
			tmp = av[i];
			av[i] = av[i + 1];
			av[i + 1] = tmp;
			i = -1;
		}
	return (av);
}

int		main(int argc, char **argv)
{
	if (argc >= 2)
	{
		argv = ft_sort_params(argc, argv);
		ft_print_params(argc, argv);
	}
	ft_putchar('\n');
	return (0);
}
