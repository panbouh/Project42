/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:03:21 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/22 12:03:34 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include <stdio.h>

int			check_line(char *line)
{
	int		i;
	int		nb;

	nb = 1;
	while (nb <= 9)
	{
		i = 0;
		while (line[i])
		{
			if (nb == (line[i] - 48))
				break ;
			i++;
		}
		if (i == 9)
			return (nb);
		nb++;
	}
	return (ERROR);
}

int			check_col(char **grid, int col)
{
	int		y;
	int		nb;

	nb = 1;
	while (nb <= 9)
	{
		y = 0;
		while (grid[y])
		{
			if (nb == (grid[y][col] - 48))
				break ;
			y++;
		}
		if (y == 9)
			return (nb);
		nb++;
	}
	return (ERROR);
}

int			sudoku(char **grid)
{
	print_grid(grid);
	return (OK);
}

/*
**	int			check_block(char **grid, int y, int x)
**	{
**	int nb;
**	int	i;
**
**	nb = 1;
**	y = y - (y % 3);
**	x = x - (x % 3);
**	i = 0;
**	while (nb <= 9)
**	{
**	while (i < 9)
**	{
**	if (i == 3 || i == 6)
**	{
**	y++;
**	x -= 3;
**	}
**	if (nb == grid[y][x] - 48)
**	break ;
**	i++;
**	x++;
**	}
**	if (i == 9)
**	return (nb);
**	nb++;
**	}
**	return (ERROR);
**	}
**
**
**
** 	int			sudoku(char **grid)
** 	{
**	int		x;
**	int		y;
**	int		nb;
**
**	x = 0;
**	y = 0;
**	while (grid[y])
**	{
**	while (grid[y][x])
**	{
**	if (grid[y][x] == VOID_PLACE)
**	{
**	if ((nb = check_line(grid[y]))
**	!= ERROR && nb == check_block(grid, y, x)
**	&& nb == check_col(&grid[0], x))
**	grid[y][x] = nb + 48;
**	}
**	x++;
**	}
**	y++;
**	}
**	print_grid(grid);
**	return (OK);
**	}
*/
