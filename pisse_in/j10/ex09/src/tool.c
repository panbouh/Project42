/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:09:22 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/24 16:43:18 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		skip_bad_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13)
				|| (str[i] == ' ')))
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int	nb;
	int	i;
	int	mult;

	nb = 0;
	i = skip_bad_chars(str);
	mult = 1;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (nb == 0)
			nb++;
		else
			return (0);
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	nb = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb * mult);
}
