/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 10:48:31 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/27 13:21:19 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

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

void	ft_print_words_tables(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		ft_putchar('\n');
		ft_putnbr(par->size_param);
		ft_putchar('\n');
		ft_print_words_tables(par->tab);
		par++;
	}
}
