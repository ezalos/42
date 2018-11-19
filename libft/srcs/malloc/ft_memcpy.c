/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:04:04 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/19 18:48:57 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
//	char	*src_c;

//	src_c = (char*)src;
	i = -1;
	while (++i < n)
		((int*)dest)[i] = ((int*)src)[i];
	return (dest);
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("\n%s\n%s\n----------------\n", argv[1], argv[2]);
		printf("%s\n", (char*)ft_memcpy(argv[1], argv[2], atoi(argv[3])));
	}
	return 0;
}
