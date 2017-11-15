/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 08:25:46 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/10 08:29:14 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_digits(int nb1, int nb2)
{
	ft_putchar(nb1 / 10 + 48);
	ft_putchar(nb1 % 10 + 48);
	ft_putchar(' ');
	ft_putchar(nb2 / 10 + 48);
	ft_putchar(nb2 % 10 + 48);
	if (nb1 != 98 || nb2 != 99)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int nb1;
	int nb2;

	nb1 = 0;
	nb2 = 0;
	while (nb1 <= 99)
	{
		while (nb2 <= 99)
		{
			if (nb2 > nb1)
				print_digits(nb1, nb2);
			nb2 += 1;
		}
		nb1 += 1;
		nb2 = 0;
	}
}
