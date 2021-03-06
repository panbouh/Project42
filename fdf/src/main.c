/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:21:25 by ccatoire          #+#    #+#             */
/*   Updated: 2017/11/20 13:21:25 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int			fd;
	t_map		map;

	if (ac != 2)
		return (ft_error(USE, FAIL));
	if ((fd = open (av[1], O_RDONLY)) == FAIL)
		return (ft_error(BAD_FD, FAIL));
	map = init_map(fd);
	ft_putstab(map.map);		//debug
	fdf(map);
	return (0);
}