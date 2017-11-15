/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:58:08 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/26 23:08:06 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "colle02.h"

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

void	ft_putnbr(int nb)
{
	int div;

	div = 1;
	while ((nb / div) > 9)
		div *= 10;
	while (div > 0)
	{
		ft_putchar(((nb / div) % 10) + 48);
		div /= 10;
	}
}

void	ft_putcolle(t_info_glue glue)
{
	ft_putstr("[colle-0");
	ft_putnbr(glue.id);
	ft_putstr("] [");
	ft_putnbr(glue.x);
	ft_putstr("] [");
	ft_putnbr(glue.y);
	ft_putstr("]\n");
}
