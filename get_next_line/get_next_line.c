/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:03:34 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/09 00:24:28 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		last_line(char **line, t_list *gnl, int end)
{
	int		size_line;

	if (!end)
	{
		*line = ft_strsub((char*)gnl->content, 0, ft_strlen((char*)gnl->content));
		free(gnl);
		return (1);
	}
	size_line = (int)(ft_strchr((char*)gnl->content, '\n') - (char*)gnl->content);
	*line = ft_strsub((char*)gnl->content, 0, size_line);

	ft_memmove((char*)gnl->content, (char*)gnl->content + size_line, ft_strlen((char*)gnl->content) - size_line);
	return (0);
}

int		save_file(t_list *gnl, char *buf)
{
	char	*old_line;
	int		size_save;
	size_t	i;

	size_save = ft_strlen((char*)gnl->content);
	old_line = (char*)gnl->content;
	if (NULL == ((char*)gnl->content = (char*)ft_memalloc(sizeof(char) * (size_save + BUFF_SIZE + 1))))
		return (-2);
	ft_strlcat(ft_strcpy((char*)gnl->content, old_line), buf, size_save + BUFF_SIZE + 1);
	free(old_line);
	i = 0;
	while (i < BUFF_SIZE && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (i);
	return (-1);
}

int		get_line(t_list *gnl, char **line)
{
	char			buf[BUFF_SIZE];
	int				v_read;
	int				v_save;

	while (-1 != (v_read = read(gnl->content_size, buf, BUFF_SIZE)))
	{
		if (-1 > (v_save = save_file(gnl, buf)))
			return (0);
		if (v_read < BUFF_SIZE)
			return (last_line(line, gnl, 1));
		if (v_save >= 0)
			return (last_line(line, gnl, 0));
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	*gnl;
	t_list			*tmp;

	if (gnl->content_size == 0)
	{
		gnl = ft_lstnew(0, fd);
		return (get_line(gnl, line));
	}
	tmp = gnl;
	while (tmp->next != NULL)
	{
		if ((const int)tmp->content_size == fd)
			return (get_line(tmp, line));
		tmp = tmp->next;
	}
	ft_lstadd(&tmp, ft_lstnew(0, fd));
	return (get_line(tmp->next, line));
}
