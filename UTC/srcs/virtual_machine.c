/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:22:39 by ldevelle          #+#    #+#             */
/*   Updated: 2019/09/05 11:22:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void ft_tictactoe(char *board, int quiet)
{
	int turn = -1;

	// printf("\033[2J");
	if (NB_AI == 0)
		while (check_winner(board) == PLAY_NONE && ++turn < 9)
		{
			printf("\033[3;0H");
			ft_print_board(board);
			do_move_from_key(board, (turn % 2) == 0 ? PLAY_ONE : PLAY_TWO);

		}
	else
    {
		beau_gosse(board, turn, quiet);
    }
	//ft_print_board(board);
	// if (check_winner(board) == PLAY_ONE)
	// 	print_victory();
	// else if (check_winner(board) == PLAY_TWO)
	// 	print_defeat();
    if (!quiet)
	    printf("the winner is %c\n", check_winner(board));

}
