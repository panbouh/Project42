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

//#include "mlx.h"
#include "../minilibx/mlx.h"
#include "libft.h"

# define	USE		"Use :\n./fdf [MAP.fdf]"
# define	BAD_FD	"File not found."
# define	WIN_X	800
# define	WIN_Y	400

typedef	struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

void	fdf(const char **map);

#endif
