/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:46:16 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/30 17:46:19 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long			ft_power(long nb, long power)
{
	long	i;
	long	pow;

	i = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	pow = nb;
	while (i < power)
	{
		nb = nb * pow;
		i++;
	}
	return (nb);
}
