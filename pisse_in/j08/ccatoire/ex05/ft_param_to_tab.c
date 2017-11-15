/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:22:49 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/27 13:19:13 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

int					paramlen(char *str)
{
	int				i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*dup;
	int		i;
	int		size;

	i = 0;
	size = paramlen(src);
	if ((dup = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (i < size)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*stock;
	int				i;
	int				size;

	size = ac + 1;
	if (!(stock = (struct s_stock_par*)malloc(sizeof(struct s_stock_par)
	* size)))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stock[i].size_param = paramlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strdup(av[i]);
		stock[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	stock[i].str = 0;
	return (stock);
}
