/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 16:36:31 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/19 17:24:03 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strdup(char *src)
{
	char	*dup;
	int		i;
	int		size;

	i = 0;
	size = len(src);
	if ((dup = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (i < size)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
