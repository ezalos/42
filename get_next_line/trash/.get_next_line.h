/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:03:44 by ldevelle          #+#    #+#             */
/*   Updated: 2018/12/12 16:13:41 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

#define _RED     "\x1b[31m"
#define _GREEN   "\x1b[32m"
#define _YELLOW  "\x1b[33m"
#define _BLUE    "\x1b[34m"
#define _MAGENTA "\x1b[35m"
#define _CYAN    "\x1b[36m"
#define _RESET   "\x1b[0m"

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

//gcc main.c get_next_line.c get_next_line.h libft.a libft.h

//gcc main.c get_next_line.c get_next_line.h libft.h ..\libft\ft_strlen.c ..\libft\ft_strsub.c ..\libft\ft_strchr.c ..\libft\ft_memmove.c ..\libft\ft_memalloc.c ..\libft\ft_strcpy.c ..\libft\ft_strlcat.c ..\libft\ft_lstadd.c ..\libft\ft_lstnew.c ..\libft\ft_strnew.c ..\libft\ft_strncpy.c ..\libft\ft_memcpy.c

int		get_next_line(const int fd, char **line);

#endif
