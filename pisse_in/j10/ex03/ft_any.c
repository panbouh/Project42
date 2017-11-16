/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:30:16 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/27 13:38:57 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_any(char **tab, int (*f)(char*))
{
	int	y;

	y = 0;
	while (tab[y])
	{
		if (f(tab[y]) == 1)
			return (1);
		y++;
	}
	return (0);
}