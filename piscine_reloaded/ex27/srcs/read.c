/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:37:13 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/16 18:11:13 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_read(int file_descriptor)
{
	char	reader;
	int		buffer;
	int		secure;

	secure = 0;
	buffer = 1 * sizeof(char);
	secure = read(file_descriptor, &reader, buffer);
	if (secure < 0)
		return (ft_error("Error during reading process\n"));
	while (secure == buffer)
	{
		ft_putchar(reader);
		secure = read(file_descriptor, &reader, buffer);
	}
	return (1);
}
