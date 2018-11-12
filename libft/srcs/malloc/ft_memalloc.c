/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:06:53 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/12 16:20:32 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

void*	ft_memalloc(size_t size)
{
	size_t	*exact;

	if(size < 1 || !(exact = (*size_t)malloc(sizeof(size_t) * size)))
		return (NULL);
	while (size >= 0)
		exact[size--] = 0;
	return (exact);
}
