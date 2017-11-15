/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:38:57 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/17 16:11:58 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

char	ig_case(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 32);
	else
		return (c);
}

int	skip_c(char *str, int i, char c)
{
	while (str[i] && str[i] == c)
		i++;
	return (i);
}

int	skip_all(char *str, int i)
{
  while (str[i] && str[i] != ' ')
    i++;
  return (i);
}

int		cmp_alert(char *s1, char *s2, int size)
{
	int	i;
	int j;
	int tamer;

	i = 0;
	while (s1[i])
	{
		j = 0;
		tamer = 0;
		i = skip_c(s1, i, ' ');
		while (s1[i] && s2[j]) 
		{
			if (ig_case(s1[i]) != ig_case(s2[j]))
				break;
			j++;
			i++;
		}
		if (j == size)
			return (1);
		i = skip_all(s1, i);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 1)
		return (0);
	while (av[i])
	{
		if (cmp_alert(av[1], "president", 9) == 0 ||
				cmp_alert(av[1], "attack", 6) == 0|| cmp_alert(av[1], "powers", 6) == 0)
		{
			return (0);
		}
	}
	return (0);
}
