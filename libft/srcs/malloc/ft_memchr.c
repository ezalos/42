/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:13:07 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/19 19:22:14 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while ((((unsigned char*)s)[i] != (unsigned char)c) && i < n)
		++i;
	if (n == i)
		return (NULL);
	return ((void*)s + i);
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("\n%s\n%s\n----------------\n", argv[1], argv[2]);
		printf("%s\n", (char*)ft_memchr(argv[1], (int)argv[2][0], atoi(argv[3])));
	}
	return 0;
}
