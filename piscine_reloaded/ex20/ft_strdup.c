/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:08:32 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/08 16:14:54 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strdup(char *src)
{
    char* dest;
    int i;

    if(!(dest = (char*)malloc(char * (ft_strlen(src) + 1))))
        return NULL;
    i = -1;
    while (str[++i])
        dest[i] = src[i];
    dest[i] = '\n';
    return (dest);
}
