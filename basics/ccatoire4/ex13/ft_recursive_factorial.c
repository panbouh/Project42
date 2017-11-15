/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:30:25 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/16 15:03:24 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 13)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	nb = nb * ft_recursive_factorial(nb - 1);
	return (nb);
}
