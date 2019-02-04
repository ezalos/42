# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 22:37:57 by ldevelle          #+#    #+#              #
#    Updated: 2019/02/04 04:48:44 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

link =	https://github.com/ezalos/

home = ~/42/

srcs =	fill_it\
		gnl\
		libft\
		ft_printf\
		time_exe\
		sudoku

#srcs = sudoku

git_link = $(srcs:%=$(link)%.git)

git_order = $(git_link:%=git clone % ;)

git_push = $(srcs:%=cd $(home)% ; git add -A ; git status ; git commit -m "MASTER Makefile automated push" ; git push ;)

git_submodules_add = $(git_link:%=git submodule add % ; )

dl :
		$(git_order)

push :
		$(git_push)

pull :

submodule :
			$(git_submodules_add)

rmdl :
		rm -rf $(srcs)
