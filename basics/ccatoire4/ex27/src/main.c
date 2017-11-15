/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:51:04 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/10 13:58:57 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "display_file.h"

void	print(char c, int fd)
{
	write(fd, &c, 1);
}

void	print_str(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		print(str[i++], fd);
}

int		main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		if (ac == 1)
			print_str("File name missing.\n", 2);
		else
			print_str("Too many arguments.\n", 2);
		return (-1);
	}
	if (!(fd = open(av[1], O_RDONLY)))
		return (-1);
	if (!(display_file(fd)))
		return (-1);
	return (0);
}
