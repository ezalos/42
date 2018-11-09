/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:14:52 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/09 17:55:13 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_putchar(char c);

void ft_print_params(int ac, char **av)
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

int     main(int ac, char **av)
{
    int i;

    i = 1;
    if (ac >= 2)
        ft_print_params(ac, av);
    ft_putchar('\n')
    return (0);
}
