/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:36:11 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/21 18:27:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	count_words(char *s, char c)
{
	int 	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c)
		{
			i++;
			while (*s != c)
				s++;
		}
	}
	return (i);
}

int	static	count_letters(char *s, char c)
{
	int 	i;

	i = 0;
	while (*(char*)s)
	{
		while (*s == c)
			s++;
		while (*s != c)
			i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		word;
	int		letter;
	int		i;

	i = -1;
	word = count_words(((char*)s), c);
	if (word < 1)
		return (NULL);
	if (!(words = (char**)malloc(sizeof(char*) * word)))
		return (NULL);
	while (++i < word)
	{
		while (*((char*)s) == c)
			s++;
		letter = count_letters(((char*)s), c);
		if (!(words[i] = ft_strsub(((char*)s), 0, letter)))
			return (NULL);
	}
	return (words);
}
