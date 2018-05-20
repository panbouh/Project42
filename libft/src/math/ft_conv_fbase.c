/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_fbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:13:18 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:13:20 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_conv_fbase(char *nb, int base)
{
	unsigned int	conv;
	size_t			i;
	size_t			size;
	int				res;

	conv = 0;
	i = 0;
	res = 0;
	size = ft_strlen(nb) - 1;
	while (nb[i])
	{
		if (ft_isalpha(nb[i]))
			conv += (nb[i] - 39 - 48) * ft_power(base, size - i);
		else
			conv += (nb[i] - 48) * ft_power(base, size - i);
		i++;
	}
	return (conv);
}
