/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:07:29 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/27 13:43:00 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	do_op(int a, int b, char *op)
{
	if (!ft_strcmp(op, "+"))
		do_sum(a, b);
	else if (!ft_strcmp(op, "-"))
		do_sub(a, b);
	else if (!ft_strcmp(op, "*"))
		do_mult(a, b);
	else if (!ft_strcmp(op, "/"))
		do_div(a, b);
	else if (!ft_strcmp(op, "%"))
		do_mod(a, b);
	else
		ft_putnbr(0);
}

int		main(int ac, char **av)
{
	int	a;
	int	b;

	if (ac != 4)
		return (ERROR);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	do_op(a, b, av[2]);
	ft_putchar('\n');
	return (0);
}
