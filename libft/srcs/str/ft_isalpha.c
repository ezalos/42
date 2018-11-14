/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:13:40 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/14 11:26:48 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

int		ft_isalpha(int c);
{
	return (ft_islower(c) || ft_tolower(c));
}
