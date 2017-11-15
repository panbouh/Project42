/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 10:34:24 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/30 18:07:26 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			lenparams(char **params)
{
	int		x;
	int		y;
	int		size;

	y = 0;
	size = 0;
	while (params[y])
	{
		x = 0;
		while (params[y][x])
		{
			x++;
			size++;
		}
		y++;
		size++;
	}
	return (size);
}

char		*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int		x;
	int		y;
	int		i;

	y = 1;
	i = 0;
	if (argc < 2 || argv == NULL)
		return (NULL);
	if ((str = malloc(sizeof(*str) * (lenparams(&argv[1]) + 1))) == NULL)
		return (NULL);
	while (argv[y])
	{
		x = 0;
		while (argv[y][x])
			str[i++] = argv[y][x++];
		y++;
		if (y != argc)
			str[i++] = '\n';
	}
	str[i] = '\0';
	return (str);
}
