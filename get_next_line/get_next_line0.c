/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:03:34 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/07 18:58:22 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_error_management(void)
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
}

int		save_read(char **line, char *buf, size_t i, size_t *size_line)
{
	char			*old_line;

	if (!*size_line)
	{
		*size_line += i;
		printf("\tsave_read : IF\t\ti = %zu\tsize_line = %zu\n", i, *size_line);
		if (!(*line = ft_memalloc(sizeof(char) * (i + 1))))
			return (0);
		if (!ft_strcpy(*line, buf))
			return (0);
		(*line)[i] = '\0';
		return (1);
	}
	else
	{
		*size_line += i;
		printf("\tsave_read : ELSE\ti = %zu\tsize_line = %zu\n", i, *size_line);
//		if (buf[i] == '\n')
//			i--;
		old_line = *line;
	//	ft_memalloc(sizeof(char) * (ft_strlen(line) + i));
		if (!(*line = ft_memalloc(sizeof(char) * (*size_line + 1))))
			return (0);
		if (!ft_strcpy(*line, old_line))
			return (0);
		if (!ft_strncat(*line, buf, i))
			return (0);
//		(*line)[*size_line] = '\0'; already included in ft_strncat
		if (buf[i] == '\0')//cant work if i receive xxxx\0\n|buff stop here|xx\0 in a file
			*size_line = 0;
	//	*line = ft_strjoin(*line, buf); //does it work when line == NULL ?
		free(old_line);
		return (1);
	}
}

int		is_it_line(char **line, char *buf, size_t *size_line)
{
	size_t			i;

	i = 0;
	while (i < BUFF_SIZE && buf[i] != '\n')
		i++;
	if (!(save_read(line, buf, i, size_line)))
		{
			ft_putstr("Error during save_read");
			return (-1);
		}
	if (buf[i] == '\n')
		return (1);
	if (buf[i] == '\0')
		return (0);
	return (-1);
}

int		get_line(const int fd, char **line)
{
	static size_t	size_line;
	char			buf[BUFF_SIZE];
	int 			v_read;

	size_line = 0;
	if (!(*line = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	while ((v_read = read(fd, buf, BUFF_SIZE)))
	{
		printf ("v_read = %d\n", v_read);
		if (v_read < 0)
		{
			ft_error_management();
			free(*line);
			return (-1);
		}
		if (1 == (v_read = is_it_line(line, buf, &size_line, nb_of_line)))
			return (1);
	}
	return (is_it_line(line, buf, &size_line));
}

int		get_next_line(const int fd, char **line)
{
	static size_t	nb_of_line;
	int		v_gnl;

	v_gnl = get_line(fd, line, nb_of_line);
	if (v_gnl == 1)
		nb_of_line++;
	return (v_gnl);
}
