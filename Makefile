# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 22:37:57 by ldevelle          #+#    #+#              #
#    Updated: 2019/02/16 15:13:38 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

link =	https://github.com/ezalos/

home = ~/42/

srcs =	fill_it\
		gnl\
		libft\
		ft_printf\
		time_exe\
		sudoku\
		push_swap\
		graph_theory


MSG ?= Makefile automated push
#srcs = sudoku

git_link = $(srcs:%=$(link)%.git)

git_order = $(git_link:%=git clone % ;)

git_push = $(srcs:%=cd $(home)% ; git add -A ; git status ; git commit -m "$(MSG)" ; git push ;)

git_submodules_add = $(git_link:%=git submodule add % ; )

dl :
		$(git_order)

push :
		$(git_push)
		@make git

pull :

submodule :
			$(git_submodules_add)

rmdl :
		rm -rf $(srcs)

git :
		@git add -A
		@git status
		@git commit -am "$(MSG)"
		@git push
