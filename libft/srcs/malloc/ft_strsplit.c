/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:36:11 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/16 22:01:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	static	count_words(char const *s, char c)
{
	int i;

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

int	static	count_letters(char const *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c)
			i++;
	}
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		word;
	int		letter;
	int		i;

	i = -1;
	word = count_words(s, c);
	if (word < 1)
		return (NULL);
	if (!(words = (char**)malloc(sizeof(char*) * word)))
		return (NULL);
	while (++i < word)
	{
		while (*s == c)
			s++;
		letter = count_letters(s, c);
		if (!(words[i] = ft_strsub(s, 0, letter)))
			return (NULL);
	}
	return (words);
}
