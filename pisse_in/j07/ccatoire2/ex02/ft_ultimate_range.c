/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:45:13 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/30 12:57:15 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	*r;
	int	i;
	int	size;

	i = 0;
	size = max - min;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	if ((r = malloc(sizeof(*r) * (size))) == NULL)
		return (0);
	while (min < max)
	{
		r[i] = min;
		i++;
		min++;
	}
	*range = r;
	return (size);
}
