/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:41:37 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/08 16:42:21 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"

void    set_point(t_point *point)
{
    point->x = 42;
    point->y = 21;
}

int     main(void)
{
    t_point point;
    set_point(&point);
    return (0);
}
