/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 12:18:49 by ccatoire          #+#    #+#             */
/*   Updated: 2017/09/15 12:18:51 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tlist		*ft_lstetnew(char letter, char *tetri)
{
	t_tlist	*elem;

	if (!(elem = malloc(sizeof(t_tlist))))
		return (NULL);
	if (!(letter) || !(tetri))
	{
		elem->tetri = NULL;
		elem->letter = 0;
	}
	else
	{
		elem->tetri = tetri;
		elem->letter = letter;
	}
	elem->next = NULL;
	return (elem);
}

t_tlist		*fillit_chkshp(char *str)
{
	unsigned int	i;
	char			*tmp;
	char			l;
	t_tlist			*elem;
	t_tlist			*begin;

	l = 'A';
	i = 0;
	begin = NULL;
	while (i < ft_strlen(str) && (tmp = ft_checkshape(ft_strsub(str, i, 20))))
	{
		if (!begin)
		{
			elem = ft_lstetnew(l++, tmp);
			begin = elem;
		}
		else
		{
			elem->next = ft_lstetnew(l++, tmp);
			elem = elem->next;
		}
		i += 21;
	}
	return ((tmp) ? begin : NULL);
}

int			fillit_square(char *str)
{
	size_t	m;
	size_t	size;

	m = 0;
	size = ft_strlen(str);
	while (m < size)
	{
		if (!(str[4 + m] == '\n' && str[9 + m] == '\n' && str[14 + m] == '\n' &&
					str[19 + m] == '\n'))
			return (0);
		m += 21;
	}
	return (1);
}

t_tlist		*ft_reader(char *str)
{
	int			i;
	t_tlist		*elem;

	elem = NULL;
	i = 0;
	if (!(str))
		return (0);
	while (str[i + 1])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		if (!(str[i + 2]) && str[i] == '\n')
			return (0);
		i++;
	}
	if (fillit_square(str))
		elem = fillit_chkshp(str);
	if (elem)
		return (elem);
	return (NULL);
}

char		*ft_buffer(char *pth)
{
	int		fd;
	int		end;
	char	*buf;
	char	*tmp;

	if ((fd = open(pth, O_RDONLY)) == -1 ||
		!(buf = ft_strnew(BUFFMAX_I)))
		return (0);
	end = read(fd, buf, BUFFMAX_I);
	buf[end] = '\0';
	if ((close(fd)) == -1)
		return (0);
	tmp = ft_strsub(buf, 0, ft_strlen(buf));
	free(buf);
	return (tmp);
}
