/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:03:34 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/15 14:26:27 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <stdio.h>

int		send_line(char **line, t_list *gnl)
{
	int		size_line;

	//printf(_YELLOW "WHATSUP NIGGA\n");
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
		//printf("|%s|\n", *line);
		return (1);
	}
	size_line = (int)(ft_strchr((char*)gnl->content, '\n')
	- (char*)gnl->content);
	*line = ft_strsub((char*)gnl->content, 0, size_line);
	ft_memmove((char*)gnl->content, (char*)gnl->content + size_line + 1,
	ft_strlen((char*)gnl->content));
	//printf("|%s|\n", *line);
	return (1);
}

char	*strnjoin(char **s1, char **s2, int size1, int size2)
{
	char	*tmp;

	tmp = NULL;
	if ((!s1 || !s2) || (!size1 && !size2) || (!*s1 && !*s2))
		return (NULL);
	tmp = ft_strsub(*s1, 0, size1);
	ft_strdel(s1);
	if (NULL == (*s1 = (char*)ft_memalloc(sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	if (size1 != 0)
		ft_strncpy(*s1, tmp, (size_t)size1);
	ft_strdel(&tmp);
	if (size2 != 0)
		ft_strncat(*s1, *s2, (size_t)size2);
	return (*s1);

}

char	*prt_strnjoin(char **s1, char **s2, int size1, int size2)
{
	char	*tmp;

	tmp = NULL;
																				printf(_MAGENTA "\t\t\t_______________________\n\t\t\t\t%s\n\t\t\t_______________________\n" _RESET, __func__);
																				printf(_YELLOW "(%p && %p) || (!%d && !%d) || (%p && !%p)\n" _RESET, s1, s2, size1, size2, *s1, *s2);
	if ((!s1 || !s2) || (!size1 && !size2) || (!*s1 && !*s2))
		return (NULL);
																				printf("\ts1|%s|\n", *s1);
																				write(1, "\ts2|", 4);
																				write(1, *s2, size2);
																				write(1, "|\n", 2);
																				printf("\ttmp|%s|\n", tmp);
																				printf(_CYAN "tmp = strsub(s1, 0, %d)" _RESET, size1);
	tmp = ft_strsub(*s1, 0, size1);
																				printf(_GREEN "\tdone!\n" _RESET);
																				printf("\ts1|%s|\n", *s1);
																				write(1, "\ts2|", 4);
																				write(1, *s2, size2);
																				write(1, "|\n", 2);
																				printf("\ttmp|%s|\n", tmp);
																				printf(_RED "strdel1(s1)" _RESET);
	ft_strdel(s1);
																				printf(_GREEN"\t\tdone!\n"_RESET);
																				printf(_YELLOW "s1 = malloc(%d + %d +1)" _RESET, size1, size2);
	if (NULL == (*s1 = (char*)ft_memalloc(sizeof(char) * (size1 + size2 + 1))))
																				{
																				printf(_RED "MALLOC ERROR\n" _RESET);
		return (NULL);
																				}
																				printf(_GREEN"\tdone!\n"_RESET);
																				printf("\ts1|%s|\n", *s1);
																				write(1, "\ts2|", 4);
																				write(1, *s2, size2);
																				write(1, "|\n", 2);
																				printf("\ttmp|%s|\n", tmp);
																				printf(_CYAN "strncpy(s1, tmp, %d)" _RESET, size1);
	if (size1 != 0)
																				{
		ft_strncpy(*s1, tmp, (size_t)size1);
																				printf(_GREEN"\tdone!\n"_RESET);
																				}
																				else
																				printf(_RED "\tnop\n" _RESET);
																				printf("\ts1|%s|\n", *s1);
																				write(1, "\ts2|", 4);
																				write(1, *s2, size2);
																				write(1, "|\n", 2);
																				printf("\ttmp|%s|\n", tmp);
																				printf(_RED "strdel2(tmp)" _RESET);
	ft_strdel(&tmp);
																				printf(_GREEN "\t\tdone!\n"_RESET);
																				printf(_CYAN "strncat(s1, s2, %d)" _RESET, size2);
	if (size2 != 0)
																				{
		ft_strncat(*s1, *s2, (size_t)size2);
																				printf(_GREEN"\tdone!\n"_RESET);
																				}
																				else
																				printf(_RED "\tnop\n" _RESET);
																				printf(_YELLOW "RETURN SRING |%s|\n" _RESET, *s1);
	return (*s1);

}

int		save_file(t_list *gnl, char *buf, int read)
{
	char	*new;
	int		size_save;
	int		i;

	if (gnl->content != NULL)
		size_save = ft_strlen((char*)gnl->content);
	else
		size_save = 0;
	//if (size_save >= 14)
	//{
	//	printf(_CYAN "\n\nsize_save: %d\t\t\t\t\t\tread: %d\n" _RESET, size_save, read);
	//	gnl->content = prt_strnjoin((char**)&gnl->content, &buf, size_save, read);
	//}
	//else
	//	gnl->content = strnjoin((char**)&gnl->content, &buf, size_save, read);
	buf[BUFF_SIZE] = '\0';
	new = ft_strjoin(gnl->content, buf);
	ft_strdel((char**)&gnl->content);
	gnl->content = new;
	ft_bzero(buf, BUFF_SIZE + 1);
	if (read != BUFF_SIZE)
		return (1);
	i = -1;
	while (++i <= (read + size_save))
		if (((char*)gnl->content)[i] == '\n')
			return (i);
	return (-1);
}

int		get_line(t_list *gnl, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				v_read;
	int				v_save;

	ft_bzero(buf, BUFF_SIZE + 1);
	while (0 < (v_read = read(gnl->content_size, buf, BUFF_SIZE)))
	{
		if (-2 == (v_save = save_file(gnl, buf, v_read)))
			return (-1);
		if (v_save >= 0)
			return (send_line(line, gnl));
	}
	//printf(_MAGENTA "quit?");
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
