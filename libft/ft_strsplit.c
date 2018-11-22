/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:36:11 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/22 20:04:51 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

static int	count_letters(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
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
	word = count_words(s, c);
	if (!(words = (char**)malloc(sizeof(char*) * (word + 1))))
		return (NULL);
	while (++i < word)
	{
		while (*s == c)
			s++;
		letter = count_letters(s, c);
		if (!(words[i] = ft_strsub(s, 0, letter)))
			return (NULL);
		s += letter;
	}
	words[i] = NULL;
	return (words);
}
