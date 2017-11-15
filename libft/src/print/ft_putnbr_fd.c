/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 12:23:53 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/16 12:25:50 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int div;
	int is_max;

	is_max = 0;
	div = 1;
	if (nb == -2147483648)
	{
		nb = -214748364;
		is_max = 1;
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	while ((nb / div) > 9)
		div *= 10;
	while (div > 0)
	{
		ft_putchar_fd(((nb / div) % 10) + 48, fd);
		div /= 10;
	}
	if (is_max == 1)
		ft_putchar_fd('8', fd);
}
