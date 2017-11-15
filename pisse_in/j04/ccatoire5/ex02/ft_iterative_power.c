/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:49:45 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/16 15:01:16 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int	i;
	int pow;

	i = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	pow = nb;
	while (i < power)
	{
		nb = nb * pow;
		i++;
	}
	return (nb);
}
