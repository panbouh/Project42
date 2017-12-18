/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:03:08 by ccatoire          #+#    #+#             */
/*   Updated: 2017/11/20 13:03:09 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(const char **map)
{
	int nb_p = 0;
	void	*win;
	void	*mlx;
	t_pos	p;
	t_pos	spac;

	p.x = 0;
	p.y = 0;
	spac.y = 10;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_X, WIN_Y, "BOUH");
	while (map[p.y])
	{
		p.x = 0;
		spac.x = 10;

		while(map[p.y][p.x])
		{
			mlx_pixel_put(mlx, win, p.x + spac.x, p.y + spac.y, 0x00FFFFFF);
			nb_p ++;
			printf("pixel put on x:%i, y:%i, pour %i point\n", p.x + spac.x, p.y + spac.y, nb_p);
				int old = spac.x;
			while (spac.x != old + 10)
				{
				mlx_pixel_put(mlx, win, p.x + spac.x, p.y + spac.y, 0x00FFFFFF);
					spac.x++;
				}
			p.x++;
		}
		p.y++;
		spac.y += 10;
	}
	mlx_loop(mlx);
}