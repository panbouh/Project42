/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:05:51 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/27 13:37:31 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ret_val;

	if (!(ret_val = (int*)(malloc(sizeof(int *) * length))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		ret_val[i] = f(tab[i]);
		i++;
	}
	return (ret_val);
}
