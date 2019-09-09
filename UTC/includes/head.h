/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:22:19 by ldevelle          #+#    #+#             */
/*   Updated: 2019/09/05 11:23:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "maths.h"
#include <math.h>

# define NB_AI			2


# define PLAY_ONE		'X'
# define PLAY_TWO		'O'
# define PLAY_NONE		'.'

# define WIN          1
# define DRAW         0
# define LOSS         -1


#define C_EXPLO         1.41421356237

# define PURPLE			"\033[95m"
# define BLUE			"\033[94m"
# define GREEN			"\033[92m"
# define YELLOW			"\033[93m"
# define RED			"\033[91m"
# define RESET			"\033[0m"
# define BOLD			"\033[1m"
# define UNDERLINE		"\033[4m"



void	ft_print_board(char *str);
void	ft_tictactoe(char *board, int quiet);
int     *futures(char *board, int turns);
char     beau_gosse(char *board, int depth, int quiet);

char    *init_board(void);
char    check_winner(const char *board);
void    do_move_from_key(char *board, char player);
void    do_move(char *board, int pos, char player);

char    *copy_board(char *board);
void    add_win(char winner, char* board, int depth);


long double explo_func(int nb_now, int nb_next, int win_next);

int     *db(int i);

#define is_valid_move(board, pos) board[pos] == PLAY_NONE

void print_victory(void);
void print_defeat(void);


#endif
