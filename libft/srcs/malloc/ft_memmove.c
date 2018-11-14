/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:12:31 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/14 12:29:46 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*tmp;
	int		i;

	if (n == 0)
		return (NULL)
	if (!(temp == sizeof(dest)malloc(sizeof(*dest) * n)))
		return (NULL);
	i = -1;
	while (++i < n)
		tmp[i] = src[i];
	while(--n >= 0)
		dest[n] = tmp[n];
	free(tmp);
	return (dest);
}
