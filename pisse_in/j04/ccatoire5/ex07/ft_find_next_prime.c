/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:24:46 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/15 17:31:30 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_is_prime(int nb)
{
	long	i;

	i = 3;
	if (nb <= 0 || nb == 1 || (nb % 2 == 0 && nb != 2))
		return (0);
	if (nb == 2)
		return (1);
	while ((i * i) - 1 < nb)
	{
		if ((nb % i) == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int			ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb += 1;
	return (nb);
}
