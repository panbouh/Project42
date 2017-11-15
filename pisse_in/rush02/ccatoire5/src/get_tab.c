/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sscc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaint-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:46:36 by ssaint-d          #+#    #+#             */
/*   Updated: 2017/03/26 23:11:19 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle02.h"

int				ft_strlen(char *str, char stop)
{
	int			i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != stop)
		i++;
	return (i);
}

int				ft_get_nbline(char *str)
{
	int			i;
	int			size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			size++;
		i++;
	}
	return (size);
}

char			*get_line(char *str, int *x)
{
	char		*line;
	int			i;
	int			size;

	size = ft_strlen(&str[*x], '\n');
	i = 0;
	if (!(line = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[*x];
		i++;
		++*x;
	}
	line[i] = '\0';
	return (line);
}

char			**ft_putlineintab(char *str)
{
	char		**tab;
	int			nb_line;
	int			x;
	int			i;

	x = 0;
	i = 0;
	nb_line = ft_get_nbline(str);
	if (!(tab = malloc(sizeof(char *) * (nb_line + 1))))
		return (NULL);
	while (i < nb_line)
	{
		tab[i] = get_line(str, &x);
		i++;
		x++;
	}
	tab[i] = 0;
	return (tab);
}
