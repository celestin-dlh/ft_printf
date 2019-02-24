/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:37:04 by cdelahay          #+#    #+#             */
/*   Updated: 2018/11/11 13:45:30 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_wd(char const *s, char c)
{
	int i;
	int words;
	int count;

	i = 0;
	words = 0;
	count = 0;
	if (*s != c)
		count++;
	while (*s)
	{
		if (*s == c)
			words = 1;
		else if (words == 1)
		{
			count++;
			words = 0;
		}
		s++;
	}
	return (count);
}

static int		word_len(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		s++;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*word;
	int		words_total;
	int		words_actual;
	int		i;

	if (s == NULL || !(words = (char**)malloc(sizeof(char*) * nb_wd(s, c) + 1)))
		return (NULL);
	words_total = nb_wd(s, c);
	words_actual = 0;
	i = 0;
	while (words_actual < words_total)
	{
		if (!(word = (char*)malloc(sizeof(char) * word_len((char*)s, c) + 1)))
			return (NULL);
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
			word[i++] = *s++;
		word[i] = '\0';
		words[words_actual++] = word;
		i = 0;
	}
	words[words_actual] = 0;
	return (words);
}
