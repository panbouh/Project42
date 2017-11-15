/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:16:16 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/10 14:01:42 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "display_file.h"

int			display_file(int fd)
{
	char	buff;

	if (!(fd))
		return (-1);
	while (read(fd, &buff, 1))
		print(buff, 1);
	return (0);
}
