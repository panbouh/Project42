/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 08:21:16 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/10 08:24:47 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_digit(int a, int b, int c)
{
	ft_putchar(a + 48);
	ft_putchar(b + 48);
	ft_putchar(c + 48);
	if (a != 7 || b != 8 || c != 9)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 1;
	c = 2;
	while (a <= 7)
	{
		while (b <= 9)
		{
			while (c <= 9)
			{
				if (c > a && c > b && b > a)
					print_digit(a, b, c);
				c++;
			}
			b++;
			c = 0;
		}
		a++;
		b = 0;
	}
}
