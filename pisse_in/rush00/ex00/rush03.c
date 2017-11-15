/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 12:34:49 by momar             #+#    #+#             */
/*   Updated: 2017/03/12 13:14:13 by momar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

char		getchar(int x, int y, int xmax, int ymax)
{
	char	c;

	if (y == 0 || y == ymax - 1)
	{
		if (x > 0 && x < xmax - 1)
			c = 'B';
		else
			c = (x == 0) ? 'A' : 'C';
	}
	else
		c = (x > 0 && x < xmax - 1) ? ' ' : 'B';
	return (c);
}

void		rush(int x, int y)
{
	int		xi;
	int		yi;

	if (x <= 0 || y <= 0)
		return ;
	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
		{
			ft_putchar(getchar(xi++, yi, x, y));
		}
		ft_putchar('\n');
		yi++;
	}
}
