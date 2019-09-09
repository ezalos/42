/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:22:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/09/05 11:30:57 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int main(void)
{
	char *board;
	int ite = 4000000;

    board = init_board();
    //  board[1] = 'X';
    //  board[3] = 'O';
    // int *fut = futures(board, 0);



	while (ite--)
	{
 	   board = init_board();
		ft_tictactoe(board, 1);
	}
    ite = 10;
    while (ite--)
	{
 	   board = init_board();
		ft_tictactoe(board, 0);
	}

   printf("La valore esta : %d", smallest_value(board));

	ite = -1;
	while (++ite < 17141)
	{
		if (db(ite)[1])
			printf("%d= %d | %d\n", ite, db(ite)[0], db(ite)[1]);
	}
  return (0);
}
