# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2019/05/02 18:17:15 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Push_swap

CC = gcc

CFLAGS = #-Wall -Wextra -Werror
CFLAGS =

DFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -pedantic\
-O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int\
-Werror-implicit-function-declaration -Wmain -Wparentheses -Wsequence-point\
-Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized -Wunknown-pragmas\
-Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast\
-Wwrite-strings -Wconversion -Wsign-compare -Waggregate-return\
-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations\
-Wmissing-noreturn -Wformat -Wmissing-format-attribute\
-Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs\
-Winline -Wlong-long -Wunreachable-code

#CFLAGS = $(DFLAGS)

##############################################################################
##############################################################################
##																			##
##									----									##
##									IFEQ									##
##									----									##
##																			##
##############################################################################
##############################################################################

SRCS		=	main\
				alg_bubble_sort\
				alg_quick_sort\
				alg_write_ab\
				alg_write_it_yourself\
				check\
				db_actions\
				db_global\
				init\
				lvl_actions_a\
				lvl_actions_ab\
				lvl_actions_b\
				lvl_memory\
				lvl_movements\
				menu_solve\
				out_debug\
				out_file_exit\
				out_print_push_swap\
				tool_median_sort\
				tool_perfect_ab\
				tool_perfect_ab_3\
				tool_perfect_ab_4\
				tool_perfect_ba\
				tool_stack_check\
				tool_stack_median\
				zip_action

SRC_PATH	= ./srcs

DIR_OBJ 	= ./objs/

##########################
##						##
##	   ARCHITECTURE		##
##						##
##########################

A_SRC 		= $(patsubst %,$(SRC_PATH)/%.c,$(SRCS))
A_OBJ		= $(patsubst %,$(DIR_OBJ)%.o,$(SRCS))

OBJ 		= $(patsubst %,%.o,$(SRCS))

LIB_DIR		= ./../libft
HEAD		= head.h
HEAD_DIR	= ./includes
HEAD_PATH	= $(HEAD_DIR)/$(HEAD)

LIB			= $(LIB_DIR)/libft.a

##########################
##						##
##		  DEBUG			##
##						##
##########################

VALGRIND = valgrind --track-origins=yes --leak-check=full --show-leak-kinds=definite

##########################
##						##
##		 COLORS			##
##						##
##########################

RED     = \x1b[31m
GREEN   = \x1b[32m
YELLOW  = \x1b[33m
BLUE	= \x1b[34m
MAGENTA	= \x1b[35m
CYAN	= \x1b[36m
END     = \x1b[0m

COM_COLOR   = $(BLUE)
OBJ_COLOR   = $(CYAN)
OK_COLOR    = $(GREEN)
ERROR_COLOR = $(RED)
WARN_COLOR  = $(YELLOW)
NO_COLOR    = $(END)

OK_STRING    = [OK]
ERROR_STRING = [ERROR]
WARN_STRING  = [WARNING]
COM_STRING   = Compiling

MSG ?= Makefile automated push
nb ?= 10

ARG=`ruby -e "puts (0..$(nb) - 1).to_a.shuffle.join(' ')"`

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

##############################################################################
##############################################################################
##																			##
##									-----									##
##									RULES									##
##									-----									##
##																			##
##############################################################################
##############################################################################

##########################
##						##
##		  BASIC			##
##						##
##########################

all :	$(NAME)

$(NAME): $(LIB) Makefile $(A_OBJ)
		@$(call run_and_test, $(CC) $(CFLAGS) -I./$(HEAD_DIR) $(A_OBJ) $(LIB) -o $(NAME))

$(DIR_OBJ)%.o:$(SRC_PATH)/%.c $(HEAD_PATH)
		@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $<)

$(LIB): FORCE
		@$(MAKE) -C $(LIB_DIR)

$(HEAD_PATH):
	@$(MAKE) -C $(LIB_DIR)

clean :
		@echo "\$(YELLOW)fill_objs \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"
		@rm -f $(A_OBJ)

fclean : clean
		@echo "\$(YELLOW)$(NAME) \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"
		@rm -rf $(NAME)

aclean : clean
		@$(MAKE) clean -C $(LIB_DIR)

afclean : aclean fclean
		@$(MAKE) fclean -C $(LIB_DIR)

re :	fclean all

are :	afclean all

git :
		@git add -A
		@git status
		git commit -am "$(MSG)"
		@git push

t	:	all
		@./$(NAME) $(ARG)

stat :
		@$(CC) $(CFLAGS) ./srcs/show_stats.c $(LIB) -o stats
		@./stats $(nb)

ten :
		@rm -rf tests/last
		@./$(NAME) $(ARG)
		@rm -rf tests/last
		@./$(NAME) $(ARG)
		@rm -rf tests/last
		@./$(NAME) $(ARG)
		@rm -rf tests/last
		@./$(NAME) $(ARG)
		@rm -rf tests/last
		@./$(NAME) $(ARG)
		@rm -rf tests/last
		@./$(NAME) $(ARG)
		@rm -rf tests/last
		@./$(NAME) $(ARG)
		@rm -rf tests/last
		@./$(NAME) $(ARG)
		@rm -rf tests/last
		@./$(NAME) $(ARG)
		@rm -rf tests/last
		@./$(NAME) $(ARG)

hund :	all
		@$(MAKE) ten
		@$(MAKE) ten
		@$(MAKE) ten
		@$(MAKE) ten
		@$(MAKE) ten
		@$(MAKE) ten
		@$(MAKE) ten
		@$(MAKE) ten
		@$(MAKE) ten
		@$(MAKE) ten
tho :
		@echo "0%"
		@$(MAKE) hund
		@echo "10%"
		@$(MAKE) hund
		@echo "20%"
		@$(MAKE) hund
		@echo "30%"
		@$(MAKE) hund
		@echo "40%"
		@$(MAKE) hund
		@echo "50%"
		@$(MAKE) hund
		@echo "60%"
		@$(MAKE) hund
		@echo "70%"
		@$(MAKE) hund
		@echo "80%"
		@$(MAKE) hund
		@echo "90%"
		@$(MAKE) hund
		@echo "100%"
		@$(MAKE) t MSG="../push_swap/tests/count/$(nb)" -C $(LIB_DIR)

echooo :
		@echo $(ARG)

vt	:	all
		@ $(VALGRIND) ./$(NAME) $(ARG)

FORCE:

##########################
##						##
##		 .PHONY			##
##						##
##########################

.PHONY : clean fclean re all git aclean afclean are
