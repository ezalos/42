# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2018/11/22 19:00:27 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -pedantic\
-ansi -O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int\
-Werror-implicit-function-declaration -Wmain -Wparentheses -Wsequence-point\
-Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized -Wunknown-pragmas\
-Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast\
-Wwrite-strings -Wconversion -Wsign-compare -Waggregate-return\
-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations\
-Wmissing-noreturn -Wformat -Wmissing-format-attribute\
-Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs\
-Winline -Wlong-long -Wunreachable-code

HEAD = ./includes/

FT_H = libft.h

A_SRC_P	=	$(SRC_PATH1), $(SRC_PATH2), $(SRC_PATH3),\
 			$(SRC_PATH4), $(SRC_PATH5), $(SRC_PATH6)
SRC_PATH = srcs/
SRC_PATH1 = srcs/file/
SRC_PATH2 = srcs/int/
SRC_PATH3 = srcs/list/
SRC_PATH4 = srcs/malloc/
SRC_PATH5 = srcs/str/
SRC_PATH6 = srcs/write/

SRCS =	$(SRCS1) $(SRCS2) $(SRCS3) $(SRCS4) $(SRCS5) $(SRCS6)

SRCS1 = putchar_fd putendl_fd putnbr_fd putstr_fd
SRCS2 = atoi intlen itoa
SRCS3 =	lstadd lstdel lstdelone lstiter lstmap lstnew
SRCS4 = memalloc memccpy memchr memcmp memcpy memdel memmove memset\
		strdel strdup strnew strsplit strsplitstr
SRCS5 = bzero char_srch isalnum isalpha isascii isdigit islower\
		isprint isupper strcat strchr strclr strcmp strcpy strequ\
		striter striteri strjoin strlcat strlen strmap strmapi strncat\
		strncmp strncpy strnequ strnstr strrchr strstr strsub strtrim tolower\
		toupper
SRCS6 = putchar putendl putnbr putstr

A_SRC =	$(addsuffix .c, $(addprefix $(SRC_PATH1)ft_, $(SRCS1))\
						$(addprefix $(SRC_PATH2)ft_, $(SRCS2))\
						$(addprefix $(SRC_PATH3)ft_, $(SRCS3))\
						$(addprefix $(SRC_PATH4)ft_, $(SRCS4))\
						$(addprefix $(SRC_PATH5)ft_, $(SRCS5))\
						$(addprefix $(SRC_PATH6)ft_, $(SRCS6)))

OBJS = $(patsubst %,ft_%.o,$(SRCS))

#D_OBJS = $(addprefix $(OBJ_PATH), $(OBJS))

OBJ_PATH = $(SRCS:srcs/=objs/)

NONL = | tr -d '\n' | tr -d '\t' | tr -d ' '

#ar -rcs libft.a *.o   FONCTIONNE

all :	$(NAME)

$(NAME):	$(OBJS)
			@echo "Creating $(NAME)"
			@ar -rcs $(NAME) $(OBJS)

$(OBJS):
			@echo "Creating objects"
			@$(CC) -c $(CFLAGS) $(patsubst %,ft_%.c,$(SRCS))

#$(NAME): $(D_OBJS)
#	@$(CC) $(CFLAGS) -o $(NAME) $(D_OBJS)
#	ar -rcs $(D_OBJS)

#$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
#	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC)

d :
			@$(CC) -c $(DFLAGS) $(patsubst %,ft_%.c,$(SRCS))
			@ar -rcs $(NAME) $(OBJS)

clean :
	@echo "Cleaning objects"
	@rm -f $(OBJS) libft.h.gch

fclean : clean
	@echo "Cleaning project"
	@rm -f $(NAME)

re : fclean all

count :
		@echo "\tThere is this many potential prototypes : \t\c"
		@ls -lR $(SRC_PATH) | grep ft_ | wc -l $(NONL)
		@echo "(number of ft_ files) OR \c"
		@cat  $(SRC_PATH)*/* | grep -e int -e char -e void -e size_t -e t_list |\
		grep ft_ | grep -v -e ":+:" -e static -e while -e if -e ";" | wc -l $(NONL)
		@echo "(conditional search)\n\tYour libft.h has this many prototypes : \t\c"
		@cat -e $(HEAD)$(FT_H) | grep ft_ | wc -l $(NONL) | sed 's/$$//'

update :
		@cat $(SRC_PATH)*/* | grep -e int -e char -e void -e size_t -e t_list |\
		grep ft_ | grep -v -e ":+:" -e static -e while -e if -e ";" |\
		sed 's/$$/;/' >> $(HEAD)$(FT_H)

bhead :
		@sed -i '' "s~../../includes/libft.h~libft.h~g" $(A_SRC)

ahead :
		@sed -i '' "s~libft.h~../../includes/libft.h~g" $(patsubst %,ft_%.c,$(SRCS))

before :	bhead
			@mv -f $(A_SRC) $(HEAD)$(FT_H) ./
			@rm -rf $(SRC_PATH) ./objs/ $(HEAD)

after :	ahead
		@mkdir	$(SRC_PATH) $(SRC_PATH1) $(SRC_PATH2) $(SRC_PATH3)\
				$(SRC_PATH4) $(SRC_PATH5) $(SRC_PATH6) $(HEAD)
		@mv -f $(FT_H) $(HEAD)
		@mv -f $(patsubst %, ft_%.c, $(SRCS1)) $(SRC_PATH1)
		@mv -f $(patsubst %, ft_%.c, $(SRCS2)) $(SRC_PATH2)
		@mv -f $(patsubst %, ft_%.c, $(SRCS3)) $(SRC_PATH3)
		@mv -f $(patsubst %, ft_%.c, $(SRCS4)) $(SRC_PATH4)
		@mv -f $(patsubst %, ft_%.c, $(SRCS5)) $(SRC_PATH5)
		@mv -f $(patsubst %, ft_%.c, $(SRCS6)) $(SRC_PATH6)

git :
		@git add *
		@git status
		@git commit -am "Makefile automated push"
		@git push

check1 :
		bash /Users/ldevelle/42/42FileChecker/42FileChecker.sh

check2 :
		yes n | bash /Users/ldevelle/42/Libftest/grademe.sh

.PHONY : clean fclean re all count update bhead ahead before after git check
