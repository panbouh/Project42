/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:43:08 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/16 15:10:55 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_getword_till(const char *str, size_t *start, char stop)
{
	size_t	size;
	char	*word;

	size = ft_strlen_till(str + *start, stop);
	if (!(word = ft_strsub(str, *start, size)))
		return (NULL);
	return (word);
}

char		**ft_strsplit(const char *str, char c)
{
	size_t	i;
	size_t	y;
	char	**split;
	size_t	nb_word;

	if (!str)
		return (NULL);
	i = 0;
	y = 0;
	nb_word = ft_count_word(str, c);
	if (!(split = (char **)malloc(sizeof(char *) * (nb_word + 1))))
		return (NULL);
	while (y < nb_word)
	{
		i = ft_skip_char(str, i, c, ALL);
		split[y] = ft_getword_till(str, &i, c);
		y++;
		i = ft_skip_char(str, i, c, TILL);
	}
	split[y] = NULL;
	return (split);
}
