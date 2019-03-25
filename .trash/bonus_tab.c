/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:56:09 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 14:37:32 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

size_t	ft_strputtab_len(size_t length, size_t separation, size_t n)
{
	size_t		tab;

	if (n == 0)
		n = 1;
	tab = 0;
	while (tab + length < separation * n)
		tab += n;
	return (tab);
}

size_t	ft_strputtab(const char *s, size_t separation)
{
	if (!s)
		return (0);
	return (ft_strputtab_len(ft_strlen(s), separation, 1));
}

char	*get_string_from_str_tab(t_printf *print, char ***str, int longest)
{
	char	*to_print;
	int		i;
	int		j;

	i = (print->bonus->line * print->bonus->column * longest)
	+ print->bonus->line;
	to_print = ft_memalloc(i + 1);
	ft_memset(to_print, ' ', i);
	to_print[i] = 0;
	i = -1;
	while (++i < print->bonus->line)
	{
		j = -1;
		if (str[i])
		{
			while (++j < print->bonus->column)
			{
				if (str[i][j])
				{
					ft_memmove(to_print + (i * print->bonus->column * longest)
					+ (j * longest) + i,
					str[i][j], ft_strlen(str[i][j]));
				}
				else
					break ;
			}
			to_print[(i * print->bonus->column * longest)
			+ (print->bonus->column * longest) + i] = '\n';
		}
		else
			break ;
	}
	to_print[(i * print->bonus->column * longest) + i] = 0;
	return (to_print);
}

int		tab_gestion(t_printf *print, const char **f)
{
	char	*to_print;
	char	***str;
	int		longest;
	int		i;
	int		j;

	str = NULL;
	(*f)++;
	get_value_of_star_or_nb(print, f, &print->bonus->line);
	while (**f != ';')
		(*f)++;
	(*f)++;
	get_value_of_star_or_nb(print, f, &print->bonus->column);
	(*f)++;
	longest = -1;
	if (**f == 's' && print->bonus->line && print->bonus->column)
	{
		str = va_arg(print->ap, char***);
		if (!str)
			return (0);
		i = -1;
		while (++i < print->bonus->line)
		{
			j = -1;
			if (str[i])
				while (++j < print->bonus->column)
				{
					if (str[i][j])
					{
						if (longest <= (int)ft_strlen(str[i][j]))
							longest = ft_strlen(str[i][j]);
					}
					else
						j = print->bonus->column;
				}
			else
				i = print->bonus->line;
		}
		to_print = get_string_from_str_tab(print, str, longest + 1);
		(*f)++;
		if (!get_printf(print, &to_print, ft_strlen(to_print)))
			return (-1);
		return (0);
	}
	(*f)++;
	return (0);
}
