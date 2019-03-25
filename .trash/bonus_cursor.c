/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cursor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:56:12 by ldevelle          #+#    #+#             */
/*   Updated: 2019/03/19 14:59:34 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/head.h"

char		*ft_str_place_cursor(size_t line, size_t column)
{
	char		*string;
	char		*tmp;
	char		*nb;

	if (!(nb = ft_nb_to_a(line, 10)))
		return (0);
	if (!(string = ft_strjoin("\033[", nb)))
		return (0);
	ft_strdel(&nb);
	if (!(tmp = ft_strjoin(string, ";")))
		return (0);
	ft_strdel(&string);
	if (!(nb = ft_nb_to_a(column, 10)))
		return (0);
	if (!(string = ft_strjoin(tmp, nb)))
		return (0);
	ft_strdel(&nb);
	ft_strdel(&tmp);
	if (!(tmp = ft_strjoin(string, "H")))
		return (0);
	ft_strdel(&string);
	return (tmp);
}

static char	*ft_move_cursor_dir(size_t quantity, const char dir)
{
	char	*nb;
	char	*to_print;

	if (!(nb = ft_nb_to_a(quantity, 10)))
		return (0);
	if (!(to_print = ft_strjoin_multi(3, "\033[", nb, &dir)))
		return (0);
	write(1, to_print, ft_strlen(to_print));
	ft_strdel(&nb);
	return (to_print);
}

char		*ft_move_cursor(size_t up, size_t down, size_t right, size_t left)
{
	char	*str;

	str = NULL;
	if (up)
		if (!(str = ft_move_cursor_dir(up, 'A')))
			return (0);
	if (down)
		if (!(str = ft_move_cursor_dir(up, 'B')))
			return (0);
	if (right)
		if (!(str = ft_move_cursor_dir(up, 'C')))
			return (0);
	if (left)
		if (!(str = ft_move_cursor_dir(up, 'D')))
			return (0);
	return (str);
}

int			encapsulated_print_cursor(t_printf *print, int dir, int tmp)
{
	char	*str;

	if (dir == 0 && !(str = ft_move_cursor(tmp, 0, 0, 0)))
			return (-1);
	else if (dir == 1 && !(str = ft_move_cursor(0, tmp, 0, 0)))
			return (-1);
	else if (dir == 2 && !(str = ft_move_cursor(0, 0, tmp, 0)))
			return (-1);
	else if (dir == 3 && !(str = ft_move_cursor(0, 0, 0, tmp)))
			return (-1);
	else
		return (-1);
	if (!get_printf(print, &str, ft_strlen(str)))
		return (-1);
	return (0);
}

int			we_need_to_move_cursor(t_printf *print, const char **f, int mode)
{
	char	*str;
	int		tmp;

	str = NULL;
	if (**f == '|')
		(*f)++;
	while (**f != '|' && mode--)
	{
		if (**f == '*' || ft_isdigit(**f))
			get_value_of_star_or_nb(print, f, &tmp);
		else
			tmp = 1;
		if (**f == '^' && (encapsulated_print_cursor(print, 0, tmp) == -1)
				return (-1);
		else if (**f == 'v' && encapsulated_print_cursor(print, 1, tmp) == -1)
				return (-1);
		else if (**f == '>' && encapsulated_print_cursor(print, 2, tmp) == -1)
				return (-1);
		else if (**f == '<' && encapsulated_print_cursor(print, 3, tmp) == -1)
				return (-1);
		(*f)++;
	}
	if (**f == '|')
		(*f)++;
	return (0);
}

int			cursor_gestion(t_printf *print, const char **f)
{
	char	*str;

	str = NULL;
	(*f)++;
	if (**f == 's')
	{
		if (!(str = ft_strdup("\033[s")))
			return (-1);
		(*f)++;
		if (!get_printf(print, &str, ft_strlen(str)))
			return (-1);
		return (0);
	}
	else if (**f == 'l')
	{
		if (!(str = ft_strdup("\033[u")))
			return (-1);
		(*f)++;
		if (!get_printf(print, &str, ft_strlen(str)))
			return (-1);
		return (0);
	}
	else if (**f == 'r')
	{
		if (!(str = ft_strdup("\033[0;0H")))
			return (-1);
		(*f)++;
		if (!get_printf(print, &str, ft_strlen(str)))
			return (-1);
		return (0);
	}
	else if (**f == '|')
		we_need_to_move_cursor(print, f, -1);
	else if (ft_char_srch(**f, "^v<>"))
		we_need_to_move_cursor(print, f, 1);
	else if (**f == '(')
	{
		(*f)++;
		get_value_of_star_or_nb(print, f, &print->bonus->line);
		while (**f != ';')
			(*f)++;
		(*f)++;
		get_value_of_star_or_nb(print, f, &print->bonus->column);
		while (**f != ')')
			(*f)++;
		(*f)++;
		if (!(str = ft_str_place_cursor(print->bonus->line,
			print->bonus->column)))
			return (-1);
		if (!get_printf(print, &str, ft_strlen(str)))
			return (-1);
		return (0);
	}
	(*f)++;
	return (0);
}
