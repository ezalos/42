/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:56:49 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/14 11:27:59 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

int		ft_islower(int c);
{
	return (c >= 'a' && c <= 'z');
}
