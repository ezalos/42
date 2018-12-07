/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:03:34 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/07 20:10:54 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strnrchr(const char *s, int c, int n, int rev)
{
	int		walker;
	int 	i;

	i = 0;
	if (rev == 1)
	{
		walker = ft_strlen(s) + 1;
		if (c == 0)
			return (walker - 1);
		while (i < n)
		{
			if (walker == 0)
				return (0);
			if ((char)s[walker] == (char)c)
				i++;
			walker--;
		}
		return (walker);
	}

	if (c == 0)
		return (ft_strlen(s));
	walker = 0;
	while (i < n)
	{
		if ((char)s[walker] == 0)
			return (0);
		if ((char)s[walker] == (char)c)
			i++;
		walker++;
	}
	return (walker);
}

int		last_line(char **line, char *save, int end)
{
	if (!end)
	{
		*line = ft_strsub(save, ft_strnrchr(save, (int)'\n', 2, 1), ft_strnrchr(save, (int)'\n', 1, 1));
		return (1);
	}
	*line = ft_strsub(save, ft_strnrchr(save, (int)'\n', 1, 1), ft_strlen(save) + 1);
	free(save);
	return (0);
}

int		save_file(char **save, char *buf)
{
	char	*old_line;
	int		size_save;
	size_t	i;

	size_save = ft_strlen(*save);
	old_line = *save;
	if (!(*save = ft_memalloc(sizeof(char) * (size_save + BUFF_SIZE + 1))))
		return (-2);
	if (!ft_strcpy(*save, old_line))
		return (-2);
	if (!ft_strlcat(*save, buf, size_save + BUFF_SIZE + 1))
		return (-2);
	free(old_line);
	i = 0;
	while (i < BUFF_SIZE && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (i);
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*save;
	char			buf[BUFF_SIZE];
	int				v_read;
	int				v_save;

	while (-1 != (v_read = read(fd, buf, BUFF_SIZE)))
	{
		if (-1 > (v_save = save_file(&save, buf)))
			return (0);
		if (v_read < BUFF_SIZE)
			return (last_line(line, save, 1));
		if (v_save >= 0)
			return (last_line(line, save, 0));
	}
	return (-1);
}
