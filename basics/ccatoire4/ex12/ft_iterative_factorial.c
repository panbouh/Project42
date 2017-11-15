/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:00:31 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/16 15:03:01 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int fact;

	if (nb < 0 || nb > 13)
		return (0);
	if (nb == 0)
		return (1);
	fact = nb;
	while (fact > 1)
	{
		nb *= fact - 1;
		fact--;
	}
	return (nb);
}
