/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:03:34 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/10 22:16:25 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		send_line(char **line, t_list *gnl)
{
	int		size_line;
	int		new_line_position;

	printf("\n\nsend_line\n");

	if (NULL == ft_strchr((char*)gnl->content, '\n'))
	{
		printf("\tlast_line\n");
		*line = ft_strsub((char*)gnl->content, 0, ft_strlen((char*)gnl->content));
		return (0);
	}
	size_line = (int)(ft_strchr((char*)gnl->content, '\n') - (char*)gnl->content);
	printf("\tsize_line = %d\n", size_line);
	*line = ft_strsub((char*)gnl->content, 0, size_line);
	ft_memmove((char*)gnl->content, (char*)gnl->content + size_line + 1, ft_strlen((char*)gnl->content));
	printf("\tmy line :%s\n\tsav :%s\n", *line, (char*)gnl->content);
	return (1);
}

int		save_file(t_list *gnl, char *buf, int read)
{
	char	*old_line;
	int		size_save;
	size_t	i;
	printf("\n\nsave_file\n");
	write(1, "\tBUF : ", 7);
	write(1, buf, read);
	printf("\n\tsave :%s\n", (char*)gnl->content);
	if (read == 0)
		buf[read] = '\0';
	if (gnl->content != NULL)
		size_save = ft_strlen((char*)gnl->content);
	else
		size_save = 0;
	printf("\tft_strlen done & is equal to %d\n", size_save);
	old_line = (char*)gnl->content;
	printf("Malloc will be of size : %d (%d + %d + 1)\n", size_save + read + 1, size_save, read);
	if (NULL == (gnl->content = (char*)ft_memalloc(sizeof(char) * (size_save + read + 1))))
	{
		printf("memalloc didnt worked\n");
		return (-2);
	}
	printf("\tft_memalloc done\n");
	if (size_save != 0)
		ft_strncpy((char*)gnl->content, old_line, size_save);
	printf("\tstrncpy done\n");
	ft_strncat((char*)gnl->content, buf, read);
	printf("\tstrncat done\n");
	free(old_line);
	i = 0;
	while (i < read && buf[i] != '\n')
		i++;
	printf("\tsave :%s\n", (char*)gnl->content);
	if (buf[i] == '\n')
		return (i);
	return (-1);
}

int		get_line(t_list *gnl, char **line)
{
	char			buf[BUFF_SIZE];
	int				v_read;
	int				v_save;

	printf("\n\nget_line\n");

	while (BUFF_SIZE == (v_read = read(gnl->content_size, buf, BUFF_SIZE)))
	{
		printf("---------------READ LOOP : %d\n", v_read);
		if (-1 > (v_save = save_file(gnl, buf, v_read)))
			return (0);
		if (v_save >= 0)
			return (send_line(line, gnl));
	}
	printf("---------------LAST READ : %d\n", v_read);
	if (v_read >= 0)
		if (-1 > (v_save = save_file(gnl, buf, v_read)))
			return (0);
	if (v_save >= 0)
		return (send_line(line, gnl));
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	*gnl;
	t_list			**tmp;
	int				r_val;

	printf("\n*********************************************\nget_next_line\n");
	printf("\tOUR FILE DESCRIPTOR IS : %d\n", fd);
	if (gnl == (t_list*)NULL)
	{
		printf("\t\tTHERE IS NO STRUCT EXISTING\n");
		gnl = ft_lstnew(0, fd);
		gnl->content_size = (size_t)fd;
		gnl->next = NULL;
		printf("\t\tfd = %zu\n", gnl->content_size);
		if (0 == (r_val = get_line(gnl, line)))
		{
			printf("DELETION OF THE 1st STRUCT THAT HAS JUST BEEN CREATED\n");
			free(&((gnl)->content));
			free(gnl);
			gnl = NULL;
		}
		printf("QUIT0\n");
		return (r_val);
	}
	printf("\tgnl != NULL\n");
	tmp = &gnl;
	printf("WE SEARCH %d\t|\t%zu WE HAVE\n", fd, (*tmp)->content_size);
	if ((*tmp)->content_size == (size_t)fd)
	{
		printf("\t\tYES\n");
		if (0 == (r_val = get_line((*tmp), line)))
		{
			gnl = (*tmp)->next;
			printf("DELETE 1st STRUCT, %d\n", r_val);
			free(&((*tmp)->content));
			printf("Content done\n");
			free(*tmp);
			//ft_lstdelone(tmp, &ft_del);
			printf("Done !\n");
		}
		printf("QUIT1\n");
		return (r_val);
	}
	printf("\t\tno.\n");
	while ((*tmp)->next != NULL)
	{
		printf("\t\tsearch of the right struct\n");
		printf("WE SEARCH %d\t|\t%zu WE HAVE\n", fd, (*tmp)->next->content_size);
		if ((*tmp)->next->content_size == (size_t)fd)
		{
		printf("\t\tFOUND!");
			if (0 == (r_val = get_line((*tmp)->next, line)))
			{
				printf("DELETE STRUCT IN WHILE\n");
				ft_lstcutone(tmp, &ft_del);
			}
			printf("QUIT2\n");
			return (r_val);
		}
		(*tmp) = (*tmp)->next;
	}
	printf("\tWe are at the last link of the list\n\tLet's create a new one !\n");
	(*tmp)->next = ft_lstnew(0, fd);
	(*tmp)->next->content_size = (size_t)fd;
	if (0 == (r_val = get_line((*tmp)->next, line)))
	{
		printf("DELETE THE LAST STRUCT\n");
		ft_lstdelone(&((*tmp)->next), &ft_del);
	}
	printf("QUIT3\n");
	return (r_val);
}
