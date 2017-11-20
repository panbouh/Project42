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

void	fdf(const char **map);

#endif
