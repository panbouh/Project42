/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:51:45 by ccatoire          #+#    #+#             */
/*   Updated: 2017/07/24 15:51:45 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int		checkend(char **save, char **line, size_t i, char *buff)
{
	*line = ft_strsub(*save, 0, i);
	*save = ft_strmiam(*save, '\n');
	ft_strdel(&buff);
	return (RD_DONE);
}

static int		checkline(char *buff, int rd, char **line, int fd)
{
	static char		*save[42424242];
	size_t			i;
	char			*old;

	if (buff)
	{
		old = save[fd];
		save[fd] = ft_strjoin(save[fd], buff);
		ft_strdel(&old);
	}
	if (rd == 0 && !(save[fd]))
		return (RD_END);
	i = 0;
	while (save[fd][i])
	{
		if (save[fd][i] == '\n')
			return (checkend(&save[fd], line, i, buff));
		i++;
	}
	if (rd == 0 && !save[fd][i])
		return (checkend(&save[fd], line, i, buff));
	return (GO);
}

int				get_next_line(int fd, char **line)
{
	char	*buff;
	int		rd;
	int		ret;

	ret = GO;
	if (!line)
		return (FAIL);
	while (ret == GO)
	{
		if (!(buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
			return (FAIL);
		if ((rd = read(fd, buff, BUFF_SIZE)) < 0)
			return (FAIL);
		if (rd == 0)
			ft_strdel(&buff);
		else
			buff[rd] = 0;
		if ((ret = checkline(buff, rd, line, fd)) != GO)
			return (ret);
		ft_strdel(&buff);
	}
	return (FAIL);
}
