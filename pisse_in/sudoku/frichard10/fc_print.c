/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:06:21 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/19 11:31:18 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

void		print(char c)
{
	write(1, &c, 1);
}

void		print_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		print(str[i]);
		i++;
	}
}

void		print_grid(char **grid)
{
	int		x;
	int		y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (x == 3 || x == 6)
				print_str("| ");
			print(grid[y][x]);
			print(' ');
			x++;
		}
		print('\n');
		if (y == 2 || y == 5)
			print_str("- - - + - - - + - - -\n");
		y++;
	}
}
