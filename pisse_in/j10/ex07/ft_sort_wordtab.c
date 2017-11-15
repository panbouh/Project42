/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:52:51 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/27 13:48:02 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void		ft_sort_wordtab(char **tab)
{
	int		i;
	char	*save;

	while (tab[i])
	{
		if (tab[i + 1] && ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			save = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = save;
			i = -1;
		}
		i++;
	}
}
