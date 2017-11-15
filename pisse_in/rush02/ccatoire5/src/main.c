/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:09:37 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/26 23:15:06 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle02.h"

int				ft_tablen(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int				take_glue_id(char **colle, t_info_glue *glue)
{
	int			finx;
	int			finy;
	int			x;

	finx = ft_strlen(colle[0], '\0');
	finy = ft_tablen(colle);
	glue->y = finy;
	glue->id = 0;
	x = 1;
	if (colle[0][0] == 'o')
		glue->id = 1;
	else if (colle[0][0] == '/')
		glue->id = 2;
	else
		return (-1);
	glue->x += 1;
	while (x < finx - 1)
	{
		if ((glue->id == 1 && colle[0][x] != '-') || (glue->id == 1 && colle[0][finx - 1] != 'o'))
			return (-1);
		if ((glue->id == 2 && colle[0][x] != '*') || (glue->id == 2 && colle[0][finx - 1] != '\\'))
			return (-1);
		x++;
		glue->x += 1;
	}
	glue->x += 1;
	return (0);
}

t_info_glue		check_colle(char **colle)
{
	t_info_glue	glue;
	int			x;
	int			y;

	glue.x = 0;
	y = 1;
	if (take_glue_id(colle, &glue) == -1)
	{
		glue.id = -1;
		return (glue);
	}
	while (y < ft_tablen(colle) - 1)
	{
		x = 1;
		if (ft_strlen(colle[y], '\0') > glue.x)
		{
			glue.id = -1;
			return (glue);
		}
		while (colle[y][x])
		{
			if ((glue.id == 1 && colle[y][x] != ' ' && colle[y][0] != '|') || (glue.id == 1 && colle[y][ft_strlen(colle[y], '\0') - 1] != '|'))
			{
				glue.id = -1;
				return (glue);
			}
			if ((glue.id == 2 && colle[y][x] != ' ' && colle[y][0] != '*') || (glue.id == 2 && colle[y][ft_strlen(colle[y], '\0') - 1] != '*'))
			{
				glue.id = -1;
				return (glue);
			}
			x++;
		}
		y++;
	}
	return (glue);
}

int				main(void)
{
	char		**tabcolle;
	char		*colle;
	int			i;
	t_info_glue	glue;

	i = 0;
	colle = get_out();
	tabcolle = ft_putlineintab(colle);
	glue = check_colle(tabcolle);
	if (glue.id == -1)
	{
		ft_putstr("Aucune\n");
		return (0);
	}
	ft_putcolle(glue);
	return (0);
}
