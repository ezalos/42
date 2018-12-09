/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:03:44 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/09 15:43:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

//gcc main.c get_next_line.c get_next_line.h libft.a libft.h ..\libft\ft_strlen.c ..\libft\ft_strsub.c ..\libft\ft_strchr.c ..\libft\ft_memmove.c ..\libft\ft_memalloc.c ..\libft\ft_strcpy.c ..\libft\ft_strlcat.c ..\libft\ft_lstadd.c ..\libft\ft_lstnew.c ..\libft\ft_strnew.c ..\libft\ft_strncpy.c ..\libft\ft_memcpy.c

int		get_next_line(const int fd, char **line);

#endif
