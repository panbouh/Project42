/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:03:18 by ccatoire          #+#    #+#             */
/*   Updated: 2017/11/20 13:03:18 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h> //a delete
#include "my_mlx.h"

# define	USE		"Use :\n./fdf [MAP.fdf]"
# define	BAD_FD	"File not found."
# define	WIN_X	700
# define	WIN_Y	400
# define	PAD		20

typedef struct		s_map
{
	const char	**map;
	size_t		size;
	size_t		y;
}					t_map;

/*
**	main.c
*/


/*
**	fdf.c
*/
void	fdf(t_map	map);

/*
**	input.c
*/
int		keyboard_input(int key, t_mlx_env *env);
int		mouse_input(int but, int x, int y, t_mlx_env *env);

/*
**	init.c
*/
t_map		init_map(int fd);
t_mlx_env	init_all();


#endif
