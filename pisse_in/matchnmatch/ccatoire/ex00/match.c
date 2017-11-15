/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:32:28 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/19 19:55:07 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			lenstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			skip_star(char *s1, char *s2, int *i, int *y)
{
	int caca;
	int size;

	size = lenstr(s1);
	while (s2[*y] == '*')
		*y = *y + 1;
	if (s2[*y] == 0)
		return (1);
	caca = *y;
	while (s2[caca])
		caca++;
	while (s1[*i] && *i < size - caca)
		*i = *i + 1;
	return (0);
}

int			match(char *s1, char *s2)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (s1[i] && s2[y])
	{
		printf("i = %c\ny = %c\n", s1[i], s2[y]);
		if (s2[y] == '*')
			if (skip_star(s1, s2, &i, &y) == 1)
				return (1);
		printf("i = %c\ny = %c\n", s1[i], s2[y]);
		if (s1[i] != s2[y])
			return (0);
		i++;
		y++;
	}
	if (s1[i] || s2[y])
		return (0);
	return (1);
}
