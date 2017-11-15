/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:13:14 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/27 13:45:41 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	do_sub(int a, int b)
{
	ft_putnbr(a - b);
}

void	do_mult(int a, int b)
{
	ft_putnbr(a * b);
}

void	do_div(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : division by zero");
		return ;
	}
	ft_putnbr(a / b);
}

void	do_mod(int a, int b)
{
	if (b == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return ;
	}
	ft_putnbr(a % b);
}

void	do_sum(int a, int b)
{
	ft_putnbr(a + b);
}
