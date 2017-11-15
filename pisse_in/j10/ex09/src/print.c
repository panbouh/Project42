/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:08:00 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/24 16:43:27 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "do_op.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		get_div(int nb)
{
	int div;

	div = 1;
	while (nb > 9)
	{
		nb /= 10;
		div *= 10;
	}
	return (div);
}

void	ft_putnbr(int nb)
{
	int div;
	int is_max;

	is_max = 0;
	if (nb == -2147483648)
	{
		nb = -214748364;
		is_max = 1;
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	div = get_div(nb);
	while (div > 0)
	{
		ft_putchar(((nb / div) % 10) + 48);
		div /= 10;
	}
	if (is_max == 1)
		ft_putchar('8');
}
