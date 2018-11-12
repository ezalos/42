/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:07:31 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/08 16:40:33 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int min, int max)
{
    int     size;
    int     *list;

    size = max - min;
    if((size <= 0) || !(list = (int*)malloc(sizeof(int) * size)))
        return (NULL);
    while (size - (max - ++min) < size)
        list[size - (max - min - 1)] = min - 1;
    return (list);
}
