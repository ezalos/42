NAME = ft_display_file

SRCS = srcs/*.c

OBJS = objs/*.o

HEAD = includes/*.h

FLAG = 	-Wall\
		-Werror\
		-Wextra

all : $(NAME)

$(NAME): 	$(OBJS)
			gcc $(FLAG) $(OBJS)

$(OBJS):	gcc -c $(FLAG) $(SRCS) $(HEAD)

clean:		rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
