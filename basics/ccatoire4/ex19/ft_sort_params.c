/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:27:36 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/22 13:03:07 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

int			ft_strcmp(char *s1, char *s2)
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

char		**sort_tamer(char **tamer, int size)
{
	int		i;
	int		j;
	char	*caca;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		if (ft_strcmp(tamer[i], tamer[i + 1]) > 0)
		{
			caca = tamer[i];
			tamer[i] = tamer[i + 1];
			tamer[i + 1] = caca;
			i = 0;
		}
		else
			i++;
	}
	return (tamer);
}

void		print_tonper(char *tonper)
{
	int		i;

	i = 0;
	while (tonper[i])
	{
		ft_putchar(tonper[i]);
		i++;
	}
}

void		print_tamer(char **tamer)
{
	int	i;

	i = 0;
	while (tamer[i])
	{
		print_tonper(tamer[i]);
		ft_putchar('\n');
		i++;
	}
}

int			main(int ac, char **av)
{
	sort_tamer(&av[1], ac - 1);
	print_tamer(&av[1]);
	return (0);
}
