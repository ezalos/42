/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:12:32 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/12 16:20:28 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*exact;

	if(size < 1 || !(exact = (*char)malloc(sizeof(char) *  (size + 1))))
		return (NULL);
	size++;
	while (size >= 0)
		exact[size--] = '\0';
	return (exact);
}
