/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:03:34 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/12 18:34:18 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

/*int		ft_error_management(void)
{
	if (errno == EBADF)
		ft_putendl("le paramètre fd n'est pas un file descriptor valide.");
	if (errno == EFAULT)
		ft_putendl("le paramètre buf pointe en dehors de l'espace alloué.");
	if (errno == EIO)
		ft_putendl("une erreur s'est produit lors de l'accès au file system.");
	if (errno == EAGAIN)
		ft_putendl("le file descriptor est marqué comme non-bloquant est aucune données n'est disponible pour l'instant.");
	if (errno == EINTR)
		ft_putendl("la lecture sur une ressource lente a été interrompue par l'arrivée d'un signal avant que des données ne soient disponibles.");
	return (-1);
}*/

int		send_line(char **line, t_list *gnl)
{
	int		size_line;
//	int		new_line_position;

	//printf(_GREEN "\n\nsend_line\n" _RESET);
	//printf(_GREEN "\tmy line :%s|\n\tsav :%s|\n" _RESET, *line, (char*)gnl->content);
	if (gnl->content == NULL)
	{
		*line = ft_memalloc(1);
		return (0);
	}
	if (NULL == ft_strchr((char*)gnl->content, '\n'))
	{
		//printf(_GREEN "\tlast_line\n" _RESET);
		if (!(*(char*)gnl->content))
			*line = ft_memalloc(1);
		else
			*line = ft_strsub((char*)gnl->content, 0, ft_strlen((char*)gnl->content));
		ft_bzero(gnl->content, ft_strlen((char*)gnl->content));
		//printf(_GREEN "\tmy line :%s|\n\tsav :%s|\n" _RESET, *line, (char*)gnl->content);
		return (1);
	}
	size_line = (int)(ft_strchr((char*)gnl->content, '\n') - (char*)gnl->content);
	//printf(_GREEN "\tsize_line = %d\n" _RESET, size_line);
	*line = ft_strsub((char*)gnl->content, 0, size_line);
	ft_memmove((char*)gnl->content, (char*)gnl->content + size_line + 1, ft_strlen((char*)gnl->content));
	//printf(_GREEN "\tmy line :%s|\n\tsav :%s|\n" _RESET, *line, (char*)gnl->content);
	return (1);
}

int		save_file(t_list *gnl, char *buf, int read)
{
	char	*old_line;
	int		size_save;
	size_t	i;
	//printf(_CYAN "\n\nsave_file\n" _RESET);
	//write(1, "\tBUF : ", 7);
	//write(1, buf, read);
	//printf(_CYAN "\n\tsave :%s\n" _RESET, (char*)gnl->content);
	//if (read <= BUFF_SIZE)//for empty file (\c), not working yet
	//	buf[read] = '\0';
	if (gnl->content != NULL)
		size_save = ft_strlen((char*)gnl->content);
	else
		size_save = 0;
	//printf(_CYAN "\tft_strlen done & is equal to %d\n" _RESET, size_save);
	old_line = (char*)gnl->content;
	//printf(_CYAN "Malloc will be of size : %d (%d + %d + 1)\n" _RESET, size_save + read + 1, size_save, read);
	if (NULL == (gnl->content = (char*)ft_memalloc(sizeof(char) * (size_save + read + 1))))
	{
		//printf("memalloc didnt worked\n");
		return (-2);
	}
	//printf(_CYAN "\tft_memalloc done\n" _RESET);
	if (size_save != 0)
		ft_strncpy((char*)gnl->content, old_line, size_save);
	//printf(_CYAN "\tstrncpy done\n" _RESET);
	ft_strncat((char*)gnl->content, buf, read);
	//printf(_CYAN "\tstrncat done\n" _RESET);
	free(old_line);
	i = 0;
	while (i < (size_t)read && buf[i] != '\n')
		i++;
	//printf(_CYAN "\tsave :%s|\n" _RESET, (char*)gnl->content);
	if (buf[i] == '\n' || read != BUFF_SIZE)
		return (i);
	return (-1);
}

int		get_line(t_list *gnl, char **line)
{
	char			buf[BUFF_SIZE];
	int				v_read;
	int				v_save;

	//printf(_MAGENTA "\n\nget_line\n" _RESET);

/*	if (NULL != gnl->content)
		if (NULL != ft_strchr((char*)gnl->content, '\n')
			return (send_line(line, gnl));*/
	while (BUFF_SIZE == (v_read = read(gnl->content_size, buf, BUFF_SIZE)))
	{
		//printf(_MAGENTA "---------------READ LOOP : %d\n" _RESET, v_read);
		if (-1 > (v_save = save_file(gnl, buf, v_read)))
			return (0);
		if (v_save >= 0)
			return (send_line(line, gnl));
	}
	//printf(_MAGENTA "---------------LAST READ : %d\n" _RESET, v_read);
	if (v_read == -1)
		return (-1);
//		return (ft_error_management());
	if (v_read == 0 && 0 == ft_strlen(gnl->content))
		return (0);
	else
	{
		//write(1, "\tBUF : ", 7);
		//write(1, buf, BUFF_SIZE);
	}
	if (v_read > 0)
		if (-1 > (v_save = save_file(gnl, buf, v_read)))
			return (0);
	if (v_save >= 0 || v_read == 0)
		return (send_line(line, gnl));
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	*gnl;
	t_list			**tmp;
	int				r_val;

	//printf(_YELLOW "\n*********************************************\nget_next_line\n" _RESET);
	//printf(_YELLOW "\tOUR FILE DESCRIPTOR IS : %d\n", fd);
	if (gnl == (t_list*)NULL)
	{
		//printf(_YELLOW "\t\tTHERE IS NO STRUCT EXISTING\n\t\tLET'S CREATE THE 1st ONE\n" _RESET);
		gnl = ft_lstnew(0, fd);
		gnl->content_size = (size_t)fd;
		gnl->next = NULL;
		//printf(_YELLOW "\t\tfd = %zu\n" _RESET, gnl->content_size);
		//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, gnl->content, gnl->content_size, (void*)gnl->next);
		if (0 == (r_val = get_line(gnl, line)))
		{
			//printf(_YELLOW "DELETION OF THE 1st STRUCT THAT JUST HAS BEEN CREATED\n" _RESET);
			//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, gnl->content, gnl->content_size, (void*)gnl->next);
			free(((gnl)->content));
			free(gnl);
			gnl = NULL;
		}
		//else
			//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, gnl->content, gnl->content_size, (void*)gnl->next);
		//printf(_YELLOW "QUIT0%d\n" _RESET,r_val);
		return (r_val);
	}
	//printf(_YELLOW "\tgnl != NULL\n" _RESET);
	tmp = &gnl;
	//printf(_YELLOW "WE SEARCH %d\t|\t%zu WE HAVE\n" _RESET, fd, (*tmp)->content_size);
	//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, (*tmp)->content, (*tmp)->content_size, (void*)(*tmp)->next);
	if ((*tmp)->content_size == (size_t)fd)
	{
		//printf(_YELLOW "\t\tYES\n" _RESET);
		if (0 == (r_val = get_line((*tmp), line)))
		{
			//printf(_YELLOW "TMP =%p\n" _RESET, (void*)*tmp);
			//*tmp = (*tmp)->next;
			//printf(_YELLOW "TMP =%p\n" _RESET, (void*)*tmp);
			//gnl = (*tmp)->next;
			//printf(_YELLOW "DELETE 1st STRUCT, r_val : %d\n" _RESET, r_val);
			//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, (*tmp)->content, (*tmp)->content_size, (void*)(*tmp)->next);
			//free(gnl->content);
			//printf(_YELLOW "Content done\n" _RESET);
			//free(gnl);
			//gnl = *tmp;
			//ft_lstdelone(tmp, &ft_del);
			//printf(_YELLOW "Done !\n" _RESET);
		}
		//else
			//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, (*tmp)->content, (*tmp)->content_size, (void*)(*tmp)->next);
		//printf(_YELLOW "QUIT1%d\n" _RESET,r_val);
		return (r_val);
	}
	//printf(_YELLOW "\t\tno.\n" _RESET);
	while ((*tmp)->next != NULL)
	{
		//printf(_YELLOW "\t\tWHILE search of the right struct\n" _RESET);
		//printf(_YELLOW "WE SEARCH %d\t|\t%zu WE HAVE\n" _RESET, fd, (*tmp)->next->content_size);
		//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, (*tmp)->next->content, (*tmp)->next->content_size, (void*)(*tmp)->next->next);
		if ((*tmp)->next->content_size == (size_t)fd)
		{
		//printf(_YELLOW "\t\tFOUND!" _RESET);
			if (0 == (r_val = get_line((*tmp)->next, line)))
			{
				//printf(_YELLOW _YELLOW "DELETE STRUCT IN WHILE\n" _RESET);
				//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, (*tmp)->next->content, (*tmp)->next->content_size, (void*)(*tmp)->next->next);
				ft_lstcutone(tmp, &ft_del);
			}
			//else
				//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, (*tmp)->next->content, (*tmp)->next->content_size, (void*)(*tmp)->next->next);
			//printf(_YELLOW "QUIT2%d\n" _RESET,r_val);
			return (r_val);
		}
		(*tmp) = (*tmp)->next;
	}
	//printf(_YELLOW "\t\tLAST search of the right struct\n" _RESET);
	//printf(_YELLOW "WE SEARCH %d\t|\t%zu WE HAVE\n" _RESET, fd, (*tmp)->content_size);
	//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, (*tmp)->content, (*tmp)->content_size, (void*)(*tmp)->next);
	if ((*tmp)->content_size == (size_t)fd)
	{
	//printf(_YELLOW "\t\tFOUND!" _RESET);
		if (0 == (r_val = get_line((*tmp), line)))
		{
			//printf(_YELLOW _YELLOW "DELETE STRUCT IN WHILE\n" _RESET);
			//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, (*tmp)->content, (*tmp)->content_size, (void*)(*tmp)->next);
			ft_lstcutone(tmp, &ft_del);
		}
		//else
			//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, (*tmp)->content, (*tmp)->content_size, (void*)(*tmp)->next);
		//printf(_YELLOW "QUIT2%d\n" _RESET,r_val);
		return (r_val);
	}
	//printf(_YELLOW "\tWe are at the last link of the list\n\tLet's create a new one !\n" _RESET);
	(*tmp)->next = ft_lstnew(0, fd);
	(*tmp)->next->content_size = (size_t)fd;
	//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, (*tmp)->next->content, (*tmp)->next->content_size, (void*)(*tmp)->next->next);
	if (0 == (r_val = get_line((*tmp)->next, line)))
	{
		//printf(_YELLOW "DELETE THE LAST STRUCT\n" _RESET);
		//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, (*tmp)->next->content, (*tmp)->next->content_size, (void*)(*tmp)->next->next);
		ft_lstdelone(&((*tmp)->next), &ft_del);
	}
	//else
		//printf(_YELLOW "\t\tSTRUCT \n\t\t{\n\t\t\tcontent:\t|%s|\n\t\t\tcontent_size:\t%zu\n\t\t\tnext:\t\t%p\n\t\t}\n" _RESET, (*tmp)->next->content, (*tmp)->next->content_size, (void*)(*tmp)->next->next);
	//printf(_YELLOW "QUIT3%d\n" _RESET,r_val);
	return (r_val);
}
