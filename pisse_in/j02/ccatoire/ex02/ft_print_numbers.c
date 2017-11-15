/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 08:15:01 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/10 08:17:25 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	int	nbr;

	nbr = 0;
	while (nbr <= 9)
	{
		ft_putchar(nbr + 48);
		nbr++;
	}
}
