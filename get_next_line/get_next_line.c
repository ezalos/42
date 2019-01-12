/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:03:34 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/12 17:49:21 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

int		send_line(char **line, t_list *gnl)
{
	int		size_line;

	if (gnl->content == NULL)
	{
		*line = ft_memalloc(1);
		return (0);
	}
	if (NULL == ft_strchr((char*)gnl->content, '\n'))
	{
		if (!(*(char*)gnl->content))
			*line = ft_memalloc(1);
		else
			*line = ft_strsub((char*)gnl->content, 0,
			ft_strlen((char*)gnl->content));
		ft_bzero(gnl->content, ft_strlen((char*)gnl->content));
		return (1);
	}
	size_line = (int)(ft_strchr((char*)gnl->content, '\n')
	- (char*)gnl->content);
	*line = ft_strsub((char*)gnl->content, 0, size_line);
	ft_memmove((char*)gnl->content, (char*)gnl->content + size_line + 1,
	ft_strlen((char*)gnl->content));
	return (1);
}

int		save_file(t_list *gnl, char *buf, int read)
{
	char	*old_line;
	int		size_save;
	int		i;

	if (gnl->content != NULL)
		size_save = ft_strlen((char*)gnl->content);
	else
		size_save = 0;
//	old_line = NULL;
//	old_line = (char*)(gnl->content);
	if (NULL == (old_line = (char*)ft_memalloc(sizeof(char) *
	(size_save + read + 1))))
		return (-2);
	if (size_save != 0)
		ft_strncpy(old_line, (char*)gnl->content, (size_t)size_save);
	ft_strncat(old_line, buf, (size_t)read);
																				//printf(_CYAN "size_save: %d\t\t\t\t\t\tread: %d\n" _RESET, size_save, read);
																				//printf(_GREEN "old|%s|\nnew|%s|\n" _RESET, old_line, (char*)gnl->content);
	free(gnl->content);
	gnl->content = ft_strsub(old_line, 0, size_save + read);
	free(old_line);
	//old_line = NULL;
																				//printf(_RED "\t\t\t\t\t\t\told|%s|\n\t\t\t\t\t\t\tnew|%s|\n\n" _RESET, old_line, (char*)gnl->content);
	if (read != BUFF_SIZE)
		return (1);
	i = -1;
	while (i <= (read + size_save))
		if (((char*)gnl->content)[++i] == '\n')
			return (i);
	return (-1);
}

int		get_line(t_list *gnl, char **line)
{
	char			buf[BUFF_SIZE];
	int				v_read;
	int				v_save;

	while (0 < (v_read = read(gnl->content_size, buf, BUFF_SIZE)))
	{
		if (-1 > (v_save = save_file(gnl, buf, v_read)))
			return (0);
		if (v_save >= 0)
			return (send_line(line, gnl));
	}
	if (v_read == -1)
		return (-1);
	if (!(gnl->content) || 0 == ft_strlen(gnl->content))
		return (0);
	if (v_read == 0)
		return (send_line(line, gnl));
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	*gnl;
	t_list			*tmp;

	if (BUFF_SIZE < 1)
		return (-1);
	if (gnl == (t_list*)NULL)
	{
		gnl = ft_lstnew(0, fd);
		gnl->content_size = (size_t)fd;
		return (get_line(gnl, line));
	}
	tmp = gnl;
	if (tmp->content_size == (size_t)fd)
		return (get_line(tmp, line));
	while (tmp->next != NULL)
	{
		if (tmp->next->content_size == (size_t)fd)
			return (get_line(tmp->next, line));
		tmp = tmp->next;
	}
	tmp->next = ft_lstnew(0, fd);
	tmp->next->content_size = (size_t)fd;
	return (get_line(tmp->next, line));
}
