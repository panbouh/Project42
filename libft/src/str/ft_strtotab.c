/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:29:52 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:29:53 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_num(const char *str)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i++]))
		{
			size++;
			while (ft_isdigit(str[i]))
				i++;
		}
	}
	return (size);
}

static void		*lanormdemerde(int *del)
{
	free(del);
	return (NULL);
}

static size_t	init_size(const char *str, size_t *size)
{
	size_t	s_tmp;

	s_tmp = count_num(str);
	if (size)
		*size = s_tmp;
	return (s_tmp);
}

int				*ft_strtotab(const char *str, size_t *size)
{
	size_t	i;
	size_t	y;
	size_t	s_tmp;
	int		*new;

	i = 0;
	y = 0;
	if (!str[i])
		return (NULL);
	s_tmp = init_size(str, size);
	if (!(new = (int *)malloc(sizeof(int) * s_tmp)))
		return (NULL);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
			return (lanormdemerde(new));
		if (ft_isdigit(str[i]))
		{
			new[y] = ft_atoi(&str[i]);
			i += ft_count_digit(new[y++]);
		}
		else
			i++;
	}
	return (new);
}
