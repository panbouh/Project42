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

int		ft_error(char *message)
{
	ft_putendl_fd(message, 2);
	return (FAIL);
}

char	**get_map(int fd)
{
	int		rd;
	char	*file;
	char	*line;
	char	**map;
	char	*save;

	file = NULL;
	while ((rd = get_next_line(fd, &line)) != RD_END)
	{
		save = file;
		file = ft_strjoin(file, line);
		ft_strdel(&save);
		save = file;
		file = ft_strjoin(file, "\n");
		ft_strdel(&save);
	}
	map = ft_strsplit(file, '\n');
	return (map);
}


int		main(int ac, char **av)
{
	int			fd;
	const char	**map;

	if (ac != 2)
		return (ft_error(USE));
	if ((fd = open (av[1], O_RDONLY)) == FAIL)
		return (ft_error(BAD_FD));
	map = (const char **)get_map(fd);
	ft_puttab(map);		//debug
	fdf(map);
	return (0);
}