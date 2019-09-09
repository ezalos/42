/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:22:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/09/05 11:22:47 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include "maths.h"

int			base_conv(char c)
{
	if (c == PLAY_NONE)
		return (0);
	if (c == PLAY_ONE)
		return (1);
	if (c == PLAY_TWO)
		return (2);
	return (-1);
}

int			trinary_board(char *board, char *tranfo)
{
	int		result = 0;
	int		i = -1;

	while (++i < 9)
	{
		result *= 3;
		result += base_conv(board[tranfo[i] - '0']);
	}
	return (result);
}

int         smallest_value(char *board)
{
    int result;
    int tampoun;
    int i;
    char *transformations[] = transformationes;

    result = trinary_board(board, identity);
    i = 1;
    while (i < 8)
    {
        tampoun = trinary_board(board, transformations[i]);
        if (tampoun < result)
            result = tampoun;
        i++;
    }
    return (result);
}

/*
void    print_rots(char *first, char *second)
{
    int i;

    i = 0;
    while (i < 9)
    {
        printf("%c",first[second[i] - 48]);
        i++;
    }
}
*/
/*
while (rotation)
	while (mirror)
		while (juxtaposition)
			check_num
return (smallest)
*/

/*
XX0
XX0
00X

874961235
*/
