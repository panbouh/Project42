/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 10:50:21 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/22 15:37:46 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			is_alphanum(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (0);
	return (1);
}

int			count_word(char *src)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (src[i])
	{
		while (src[i] && is_alphanum(src[i]) == 0)
			i++;
		if (src[i] && is_alphanum(src[i]) == 1)
			size++;
		while (src[i] && is_alphanum(src[i]) == 1)
			i++;
	}
	return (size);
}

int			wordlen(char *str, int i)
{
	int		size;

	size = 0;
	while (str[i] && is_alphanum(str[i]) == 0)
		i = i + 1;
	while (str[i] && is_alphanum(str[i]) == 1)
	{
		size++;
		i = i + 1;
	}
	return (size);
}

char		*get_word(char *str, int *i)
{
	char	*word;
	int		x;
	int		size;

	x = 0;
	size = wordlen(str, *i);
	if ((word = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (str[*i] && is_alphanum(str[*i]) == 0)
		*i = *i + 1;
	while (str[*i] && is_alphanum(str[*i]) == 1)
	{
		word[x] = str[*i];
		x++;
		++*i;
	}
	word[x] = '\0';
	return (word);
}

char		**ft_split_whitespaces(char *str)
{
	char	**wordtab;
	int		size;
	int		y;
	int		x;

	y = 0;
	x = 0;
	size = count_word(str);
	if ((wordtab = malloc(sizeof(char*) * (size + 1))) == NULL)
		return (NULL);
	while (y < size)
	{
		wordtab[y] = get_word(str, &x);
		y++;
	}
	wordtab[y] = 0;
	return (wordtab);
}
