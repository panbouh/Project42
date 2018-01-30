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
	unsigned int n;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		n = -nb;
	}
	else
		n = nb;
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + 48, fd);
}

void	ft_putunbr_fd(unsigned long long nb, int fd)
{
	if (nb >= 10)
		ft_putlnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + 48, fd);
}

void	ft_putumaxnbr_fd(uintmax_t nb, int fd)
{
	if (nb >= 10)
		ft_putumaxnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + 48, fd);
}

void	ft_putlnbr_fd(long long nb, int fd)
{
	unsigned long long n;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		n = -nb;
	}
	else
		n = nb;
	if (n >= 10)
		ft_putlnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + 48, fd);
}

void	ft_putimaxnbr_fd(intmax_t nb, int fd)
{
	uintmax_t n;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		n = -nb;
	}
	else
		n = nb;
	if (n >= 10)
		ft_putimaxnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + 48, fd);
}

// void	ft_putnbr_fd(int nb, int fd)
// {
// 	int div;
// 	int is_max;

// 	is_max = 0;
// 	div = 1;
// 	if (nb == -2147483648)
// 	{
// 		nb = -214748364;
// 		is_max = 1;
// 	}
// 	if (nb < 0)
// 	{
// 		nb *= -1;
// 		ft_putchar_fd('-', fd);
// 	}
// 	while ((nb / div) > 9)
// 		div *= 10;
// 	while (div > 0)
// 	{
// 		ft_putchar_fd(((nb / div) % 10) + 48, fd);
// 		div /= 10;
// 	}
// 	if (is_max == 1)
// 		ft_putchar_fd('8', fd);
// }
