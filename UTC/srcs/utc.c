/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:22:30 by ldevelle          #+#    #+#             */
/*   Updated: 2019/09/05 11:23:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

long double explo_func(int nb_now, int nb_next, int win_next)
{
	// printf("%s\n", __func__);
	// long double explo_const = sqrt(2);
	long double res;

	if (!nb_next)
		nb_next++;
	res = ((long double)win_next / (long double)nb_next) + (C_EXPLO * sqrt( log(nb_now) / nb_next));
	return (res);
}

int choose_move(char *board, int depth)
{
	long double tmp = 0;
	long double res = 0;

	// printf("%s\n", __func__);
	int	*future = futures(board, depth);
	int nb_now = db(smallest_value(board))[1];

	if (!nb_now)
		nb_now++;
	int next_mov = 0;
	int i = -1;
	while (!(is_valid_move(board, next_mov)))
		next_mov++;

	while (++i < 9)
	{
		if (future[i] != 0)
		{
			res = explo_func(nb_now, db(future[i])[1], db(future[i])[0]);
            //
			if ((tmp < res))
			{
				// printf("*** ONE\n");
				res = tmp;
				next_mov = i;
			}
			// if ((tmp == res && rand() % 2))
			// {
			// 	// printf("*** ONE\n");
			// 	res = tmp;
			// 	next_mov = i;
			// }
		}
	}
	return (next_mov);
}

int win_score(char *board)
{
    char    winner;

    winner = check_winner(board);
    if (winner == '.')
        return (DRAW);
    if (winner == 'X')
        return (WIN);
    if (winner == 'O')
        return (LOSS);
    return (0);
}

/*
int beau_gosse(char *board, int depth)
{
	// printf("%s\n", __func__);
	int win = base_conv((check_winner(board)));
	// printf("-->%d\n", win);

	if (win == 2)
		win = -1;
	if (win || depth > 9)
		return (win);

	ft_print_board(board);
	int movvvv = choose_move(board, depth);
	char player = (depth % 2) ? PLAY_TWO : PLAY_ONE;
	// printf("turn %d\n%c plays : %d\n", depth, player, movvvv);
	do_move(board, movvvv, player);
	ft_print_board(board);
	win = beau_gosse(board, depth + 1);
	db(smallest_value(board))[0] += (depth % 2) ? win : -win;
	db(smallest_value(board))[1]++;
	return(win);
}
*/

char beau_gosse(char *board, int depth, int quiet)
{
    char *tmp_board = NULL;
    char winner;
    char player = (depth % 2) ? PLAY_TWO : PLAY_ONE;

    if (!quiet)
        ft_print_board(board);
    if(depth > 8 || check_winner(board) != '.')
        return (check_winner(board));
    tmp_board = copy_board(board);
    int move = choose_move(board, depth);
	do_move(board, move, player);

    winner = beau_gosse(board, depth + 1, quiet);

    add_win(winner, tmp_board, depth);

   // if (tmp_board)
   //     free(tmp_board);
   return(0);
}
