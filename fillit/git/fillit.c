/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 12:19:06 by ccatoire          #+#    #+#             */
/*   Updated: 2017/09/19 15:36:02 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_pos	get_pos(char str[][TABSIZE], char letter, int size)
{
	int		y;
	int		x;
	t_pos	p;

	p.x = 0;
	p.y = 0;
	p.s = size;
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (str[x][y] == letter)
			{
				p.x = x;
				p.y = y;
				return (p);
			}
			y++;
		}
		x++;
	}
	return (p);
}

int		tryfit(t_pos pos, char str[][TABSIZE], t_tlist *elem)
{
	if (elem)
	{
		reset_pos(&pos);
		while (pos.x <= pos.s)
		{
			while (pos.y <= pos.s)
			{
				if (ft_check_n_put(str, &pos, *elem))
				{
					if (tryfit(pos, str, elem->next) == FALSE)
					{
						remove_t(str, elem->letter, pos.s);
					}
				}
				pos.y++;
			}
			pos.y = 0;
			pos.x++;
		}
		return (FALSE);
	}
	clafaim(str, &pos);
	return (NOPE);
}

int		ft_placetet(t_tlist *tetlist)
{
	t_pos	pos;
	char	str[TABSIZE][TABSIZE];
	int		ret;

	pos.x = 0;
	pos.y = 0;
	pos.s = firstalloc(tetlist);
	set_map(str);
	ret = TRUE;
	while ((ret = tryfit(pos, str, tetlist)) != NOPE)
	{
		if (ret == FALSE)
			pos.s++;
	}
	return (1);
}
