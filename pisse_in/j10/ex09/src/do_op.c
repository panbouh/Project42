/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:13:14 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/24 16:44:05 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
	ft_putchar('\n');
}

void	ft_mul(int a, int b)
{
	ft_putnbr(a * b);
	ft_putchar('\n');
}

void	ft_div(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return ;
	}
	ft_putnbr(a / b);
	ft_putchar('\n');
}

void	ft_mod(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return ;
	}
	ft_putnbr(a % b);
	ft_putchar('\n');
}

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
	ft_putchar('\n');
}
