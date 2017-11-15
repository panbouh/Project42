/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:32:01 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/13 16:45:22 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_int(int *a, int *b)
{
	int	save;

	save = *a;
	*a = *b;
	*b = save;
}

void	ft_sort_integer_table(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap_int(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
