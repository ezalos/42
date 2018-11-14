# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2018/11/14 13:06:41 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC = includes

A_SRC_P	=	$(SRC_PATH1), $(SRC_PATH2), $(SRC_PATH3),\
 			$(SRC_PATH4), $(SRC_PATH5), $(SRC_PATH6)
SRC_PATH1 = srcs/file/ft_
SRC_PATH2 = srcs/int/ft_
SRC_PATH3 = srcs/list/ft_
SRC_PATH4 = srcs/malloc/ft_
SRC_PATH5 = srcs/str/ft_
SRC_PATH6 = srcs/write/ft_

OBJ_PATH = $(SRCS:srcs/=objs/)

SRCS =	$(addsuffix .c, $(SRCS1), $(SRCS2), $(SRCS3), $(SRCS4), $(SRCS5),\
		$(SRCS6))
SRCS1 = putchar_fd, putendl_fd, putnbr_fd, putstr_fd
SRCS2 = atoi, intlen, itoa
SRCS3 =	lstadd, lstdel, lstdelone, lstiter, lstmap, lstnew
SRCS4 = memalloc, memccpy, memchr, memcmp, memcpy, memdel, memmove, memset,\
		strdel, strdup, strnew, strsplit, strsplitstr
SRCS5 = bzero, char_srch, isalnum, isalpha, isascii, isdigit, islower,\
		isprint, isupper, strcat, strchr, strclr, strcmp, strcpy, strequ,\
		striter, striteri, strjoin, strlcat strlen, strmap, strmapi, strncat,\
		strncmp, strnequ, strnstr, strrcher, strstr, strsub, strtrim, tolower,\
		toupper
SRCS6 = putchar, putendl, putnbr, putstr

A_SRC = $(addsuffix .c, $(addprefix $(SRC_PATH1), $(SRCS1)),\
						$(addprefix $(SRC_PATH2), $(SRCS2)),\
						$(addprefix $(SRC_PATH3), $(SRCS3)),\
						$(addprefix $(SRC_PATH4), $(SRCS4)),\
						$(addprefix $(SRC_PATH5), $(SRCS5)),\
						$(addprefix $(SRC_PATH6), $(SRCS6)))

OBJS = $(A_SRC:.c=.o)

D_OBJS = $(addprefix $(OBJ_PATH), $(OBJS))

all: $(NAME)

$(NAME): $(D_OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(D_OBJS)
	ar -rcs $(D_OBJS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC)

$(patsubst %, %.c, $(SRCS))

clean:
	@rm -f $(D_OBJS)

fclean: clean
	@echo "Cleaning project"
	@rm -f $(NAME)
	@echo "Done"

re: fclean all

.PHONY: clean fclean re all


	all: $(NAME)

	objs:
			gcc -c $(FLAG) $(SRCS) -I $(HEAD)

	$(NAME): objs
			ar rcs $(NAME) $(OBJS)

	clean:
			rm -rf $(OBJS)

	fclean:	clean
			rm -rf $(NAME)
