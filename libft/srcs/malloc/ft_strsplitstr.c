/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:41:44 by ldevelle          #+#    #+#             */
/*   Updated: 2018/11/12 16:20:08 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inclde "../../includes/libft.h"

int	static	count_words(*s, *split)
{
	int i;

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

int	static	count_letters(*s, *split)
{
	int i;

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
	word = count_words(s, split);
	if (world < 1)
		return (NULL);
	if (!(words = (char**)malloc(sizeof(char*) * word)))
		return (NULL);
	while (++i < word)
	{
		while (ft_char_srch(*s, split))
			s++;
		letter = count_letters(s, split);
		if (!(words[i] = ft_strsub(s, 0, letter))
			return (NULL);
	}
	return (words);
}
