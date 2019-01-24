/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:06:30 by ldevelle          #+#    #+#             */
/*   Updated: 2019/01/24 22:01:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct			s_print
{
	const char 			*format;
	va_list 			ap;
	char 				*backup_format;
	char				*printf;
	size_t				size;
	t_all_types			*all;
}						t_print;

typedef struct			s_all_types
{
	int					my_int;
	short				my_short;
	long				my_long;
	double		 		my_double;
	long double 		my_long_double;
	float				my_float;
	unsigned int		my_u_int;
	unsigned short		my_u_short;
	unsigned long		my_u_long;
	char				my_char;
	win_t				my_multi_char;
	char				*my_str;
	wchar_t				*my_multi_str;
	void				*my_ptr;
}						t_all_types;

# define OFFPTION

# ifdef ONPTION
#  include <stdio.h>
#  define OPTION	1
#  define _RED		"\x1b[31m"
#  define _GREEN	"\x1b[32m"
#  define _YELLOW	"\x1b[33m"
#  define _BLUE		"\x1b[34m"
#  define _MAGENTA	"\x1b[35m"
#  define _CYAN		"\x1b[36m"
#  define _RESET	"\x1b[0m"
# endif

# ifdef OFFPTION
#  define OPTION	0
#  define _RED		""
#  define _GREEN	""
#  define _YELLOW	""
#  define _BLUE		""
#  define _MAGENTA	""
#  define _CYAN		""
#  define _RESET	""
# endif

int		ft_printf(const char *format, ...);

#endif
