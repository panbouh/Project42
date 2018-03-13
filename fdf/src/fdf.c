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
#include "mlx.h"
#include "libft.h"

void	draw_map(t_map map, t_mlx_env env)
{
	t_pos	i;
	t_pos	p;
	int		pad_x;
	int		pad_y;
	int		marg_x;
	int		marg_y;
	int		color;

	i.y = 0;
	p.y = 0;
	pad_x = 10;
	pad_y = 10;
	marg_y = ft_abs(WIN_Y / 2 - map.y / 2) - (pad_y * map.y / 2);
	marg_x = ft_abs(WIN_X / 2 - ft_strlen(map.map[0]) / 2) - (pad_x * (ft_strlen(map.map[0]) / 2));
	while (map.map[i.y])
	{
		i.x = 0;
		p.x = pad_x;
		while (map.map[i.y][i.x])
		{
			mlx_pixel_put(env.mlx_p, env.win_p, p.x + marg_x, p.y + marg_y, 0x00FF00);
			p.x += pad_x;
			i.x++;
		}
		i.y++;
		p.y += pad_y;
	}
}

void	fdf(t_map map)
{
	t_mlx_env	env;

	env = init_all();

	draw_map(map, env);

	mlx_key_hook(env.win_p, &keyboard_input, &env);
	mlx_mouse_hook(env.win_p, &mouse_input, &env);
	mlx_loop(env.mlx_p);
}