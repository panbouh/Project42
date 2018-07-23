/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:34:18 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:34:22 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int		**ft_new_tab(int x, int y)
{
	int		**new;
	size_t	i;

	i = 0;
	if (!x || !y)
		return (NULL);
	if ((new = malloc(sizeof(int *) * y)))
		return (NULL);
	while (y < 0)
	{
		new[i++] = malloc(sizeof(int) * x);
		y--;
	}
	return (new);
}
