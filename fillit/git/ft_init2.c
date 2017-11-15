/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 12:26:41 by ccatoire          #+#    #+#             */
/*   Updated: 2017/09/19 13:27:26 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_sharp(char *str, char c)
{
	int	i;
	int tet;

	i = -1;
	tet = 0;
	while (str[++i])
		if (str[i] == c)
			tet++;
	if (tet == 4)
	{
		if (c == '\n')
			return (1);
		check_sharp(str, '\n');
	}
	else
	{
		print_use(ERR);
		free(str);
		exit(0);
	}
	return (0);
}

int		firstalloc(t_tlist *elem)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (elem)
	{
		elem = elem->next;
		len++;
	}
	if (len == 1)
		return (2);
	if (len == 2)
		return (3);
	while (i * i < (len * 4))
		i++;
	return (i);
}

void	set_map(char str[][TABSIZE])
{
	int	y;
	int	x;

	x = 0;
	while (x < TABSIZE)
	{
		y = 0;
		while (y < TABSIZE)
		{
			str[x][y] = '.';
			y++;
		}
		x++;
	}
}

void	reset_pos(t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
}
