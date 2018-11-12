# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2018/11/12 17:00:37 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC = includes

A_SRC_P	=	$(SRC_PATH1), $(SRC_PATH2),\
			$(SRC_PATH3), $(SRC_PATH4), $(SRC_PATH5)
SRC_PATH1 = srcs/malloc/ft_
SRC_PATH2 = srcs/file/ft_
SRC_PATH3 = srcs/str/ft_
SRC_PATH4 = srcs/write/ft_
SRC_PATH5 = srcs/int/ft_

OBJ_PATH = $(SRCS:srcs/=objs/)

SRCS =	$(SRCS1), $(SRCS2), $(SRCS3), $(SRCS4), $(SRCS5)
SRCS1 = $(addsuffix .c, memalloc, memdel, strdel, strnew, strsplit, strsplitstr)
SRCS2 = $(addsuffix .c, )
SRCS3 = $(addsuffix .c, )
SRCS4 = $(addsuffix .c, )
SRCS5 = $(addsuffix .c, )

A_SRC = $(addprefix $(SRC_PATH1), $(SRCS1))\
		$(addprefix $(SRC_PATH2), $(SRCS2))\
		$(addprefix $(SRC_PATH3), $(SRCS3))\
		$(addprefix $(SRC_PATH4), $(SRCS4))\
		$(addprefix $(SRC_PATH5), $(SRCS5))

OBJS = $(SRCS:.c=.o)

D_OBJS = $(addprefix $(OBJ_PATH), $(OBJS))

all: $(NAME)

$(NAME): $(D_OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(D_OBJS)
	ar -rcs $(D_OBJS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC)

clean:
	@rm -f $(D_OBJS)

fclean: clean
	@echo "Cleaning project"
	@rm -f $(NAME)
	@echo "Done"

re: fclean all
