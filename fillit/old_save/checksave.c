/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkshape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 16:34:11 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/19 16:12:00 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static char	*shape1(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i + 7 < 20 && str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' &&
				str[i + 7] == '#')
			return ("###\n..#");
		if (i + 7 < 20 && str[i] == '#' && str[i + 5] == '#' && str[i + 6] == '#' &&
				str[i + 7] == '#')
			return ("#\n###");
		if (i + 6 < 20 && str[i] == '#' && str[i + 4] == '#' && str[i + 5] == '#' &&
				str[i + 6] == '#')
			return (".#\n###");
		if (i + 6 < 20 && str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' &&
				str[i + 6] == '#')
			return ("###\n.#");
		i++;
	}
	return (0);
}

static char	*shape2(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i + 5 < 20 && str[i] == '#' && str[i + 3] == '#' && str[i + 4] == '#' &&
				str[i + 5] == '#')
			return ("..#\n###");
		if (i + 7 < 20 && str[i] == '#' && str[i + 1] == '#' && str[i + 6] == '#' &&
				str[i + 7] == '#')
			return ("##\n.##");
		if (i + 5 < 20 && str[i] == '#' && str[i + 1] == '#' && str[i + 4] == '#' &&
				str[i + 5] == '#')
			return (".##\n##");
		if (i + 5 < 20 && str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' &&
				str[i + 5] == '#')
			return ("###\n#");
		i++;
	}
	return (0);
}

static char	*shape3(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i + 11 < 20 && str[i] == '#' && str[i + 5] == '#' && str[i + 10] == '#' &&
				str[i + 11] == '#')
			return ("#\n#\n##");
		if (i + 10 < 20 && str[i] == '#' && str[i + 1] == '#' && str[i + 5] == '#' &&
				str[i + 10] == '#')
			return ("##\n#\n#");
		if (i + 11 < 20 && str[i] == '#' && str[i + 1] == '#' && str[i + 6] == '#' &&
				str[i + 11] == '#')
			return ("##\n.#\n.#");
		if (i + 9 < 20 && str[i] == '#' && str[i + 4] == '#' && str[i + 5] == '#' &&
				str[i + 9] == '#')
			return (".#\n##\n#");
		i++;
	}
	return (0);
}

static char	*shape4(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i + 11 < 20 && str[i] == '#' && str[i + 5] == '#' && str[i + 6] == '#' &&
				str[i + 11] == '#')
			return ("#\n##\n.#");
		if (i + 10 < 20 && str[i] == '#' && str[i + 5] == '#' && str[i + 10] == '#' &&
				str[i + 9] == '#')
			return (".#\n.#\n##");
		if (i + 10 < 20 && str[i] == '#' && str[i + 4] == '#' && str[i + 5] == '#' &&
				str[i + 10] == '#')
			return (".#\n##\n.#");
		if (i + 10 < 20 && str[i] == '#' && str[i + 5] == '#' && str[i + 6] == '#' &&
				str[i + 10] == '#')
			return ("#\n##\n#");
		if (i + 15 < 20 && str[i] == '#' && str[i + 5] == '#' && str[i + 10] == '#' &&
				str[i + 15] == '#')
			return ("#\n#\n#\n#");
		i++;
	}
	return (0);
}

char		*ft_checkshape(char *str)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	check_sharp(str, '#');
	while (str[i] && !tmp)
	{
		if (i + 6 < 20 && str[i] == '#' && str[i + 1] == '#' && str[i + 5] == '#' &&
				str[i + 6] == '#')
			tmp = "##\n##";
		else if (i + 3 < 20 && str[i] == '#' && str[i + 1] == '#' && str[i + 2] == '#' &&
				str[i + 3] == '#')
			tmp = "####";
		i++;
	}
	tmp = (!tmp) ? shape1(str) : tmp;
	tmp = (!tmp) ? shape2(str) : tmp;
	tmp = (!tmp) ? shape3(str) : tmp;
	tmp = (!tmp) ? shape4(str) : tmp;
	ft_memdel((void **)&str);
	return (tmp);
}
