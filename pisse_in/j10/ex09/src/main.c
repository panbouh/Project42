/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:07:29 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/24 16:43:35 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include "ft_opp.h"

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

void	ft_usage(int a, int b)
{
	a = b;
	ft_putstr("error : only [ + - * / % ] are accepted.\n");
}

void	do_op(int a, int b, char *op)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (g_opptab[i].key)
	{
		if (!(ft_strcmp(g_opptab[i].key, op)))
		{
			g_opptab[i].f(a, b);
			check = 1;
		}
		i++;
	}
	if (check == 0)
		ft_usage(a, b);
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
	return (0);
}
