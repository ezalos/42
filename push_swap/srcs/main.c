/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:21:29 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/01 19:32:48 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void    show_it(void)
{
	int size;

	size = -1;
	while (++size < (int)(*ft_remember_push())->all)
		ft_printf("[%d]:%d\n", size, stack_a(size));
	ft_press_any_key();
}

void	action_list(void)
{
	int i;

	i = -1;
	ft_putendl("");
	while (++i < (*ft_remember_push())->count)
		ft_printf("%d%s ", i, *(char**)ft_tab_dirth((*ft_remember_push())->actions, 0, i)->content);
	ft_putendl("");
}

int		main(int ac, char **av)
{
	time_exe(__func__);
	t_push_swap		*push;
	char			*nb;
	char			*name;
	size_t			size;
	int				fd;

	if (VISUAL_MODE)
		CLEAR_SCREEN
	if (PROGRESS)
		ft_progress("Init", 0, 3);
	if (ac <= 1)
		return (ft_putstr_r0("Error\n"));
	size = ac - 1;
	if (!(push = setup_tab(size, av)))
		return (ft_putstr_r0("Error\n"));
	if (PROGRESS)
		ft_progress("Init", 1, 3);
	size = 0;
	if ((fd = open("tests/last", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU|S_IRWXG|S_IRWXO)) > 0)
	{
		while ((int)++size < ac)
			ft_putstr_fd(av[size], fd);
		close(fd);
	}
	time_exe(__func__);
	if (PROGRESS)
		ft_progress("Init", 2, 3);
	lets_solve(push);
	// ft_printf("BEF: %d\n", push->count);
	// action_list();
	traduction();
	ft_printf("%d\n", push->count);
	time_exe(__func__);
	if (is_it_good(push))
	{
		nb = ft_nb_to_a(push->all, 0);
		if (push->all >= 500 && push->count >= 7000)
		{
			name = ft_strjoin_multi(4, "./tests/too_much/", nb, "_", ft_nb_to_a(push->count, 0));
			if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU|S_IRWXG|S_IRWXO)) > 0)
			{
				size = 0;
				while ((int)++size < ac)
				{
					ft_putstr_fd(av[size], fd);
					ft_putstr_fd(" ", fd);
				}
				close(fd);
			}
			ft_strdel(&name);
		}
		name = ft_strjoin("./tests/count/", nb);
		ft_strdel(&nb);
		nb = ft_nb_to_a(push->count, 0);
		ft_add_to_file(name, nb);
		ft_strdel(&nb);
		ft_strdel(&name);
		print_time();
		return (ft_putstr_r0("OK\n"));
	}
	else
	{
		fd = open("./tests/KO", O_RDWR);
		size = 0;
		while (++size < (size_t)ac)
			ft_printf("%~.*%~%s ", fd, av[size]);
		print_time();
		return (ft_putstr_r0("KO\n"));
	}
}
