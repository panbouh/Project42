/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:01:25 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/22 12:07:52 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include <stdio.h>

int		my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_grid(char **grid)
{
	int	x;
	int	y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		if ((my_strlen(grid[y])) != 9)
			return (ERROR);
		while (grid[y][x])
		{
			if ((grid[y][x] < '0' && grid[y][x] > '9') && grid[y][x] != '.')
				return (ERROR);
			x++;
		}
		y++;
	}
	return (OK);
}

int		main(int ac, char **av)
{
  int	test;
  
	if (check_grid(&av[1]) == ERROR)
	{
		print_str("Error\n");
		return (ERROR);
	}
	if (sudoku(&av[1])== ERROR)
		return (ERROR);
	return (0);
}
