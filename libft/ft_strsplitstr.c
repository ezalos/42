/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:41:44 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/21 17:36:49 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	count_words(char *s, char *split)
{
	int 	i;

	i = 0;
	while (*s)
	{
		while (ft_char_srch(*s, split))
			s++;
		if (!ft_char_srch(*s, split))
		{
			i++;
			while (!ft_char_srch(*s, split))
				s++;
		}
	}
	return (i);
}

int	static	count_letters(char *s, char *split)
{
	int 	i;

	i = 0;
	while (*s)
	{
		while (ft_char_srch(*s, split))
			s++;
		while (!ft_char_srch(*s, split))
			i++;
	}
	return (i);
}

char	**ft_strsplitstr(char const *s, char *split)
{
	char	**words;
	int		word;
	int		letter;
	int		i;

	i = -1;
	word = count_words(((char*)s), split);
	if (word < 1)
		return (NULL);
	if (!(words = (char**)malloc(sizeof(char*) * word)))
		return (NULL);
	while (++i < word)
	{
		while (ft_char_srch(*((char*)s), split))
			s++;
		letter = count_letters(((char*)s), split);
		if (!(words[i] = ft_strsub(((char*)s), 0, letter)))
			return (NULL);
	}
	return (words);
}
