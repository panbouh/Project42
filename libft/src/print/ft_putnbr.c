/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 12:28:09 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/16 12:28:10 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	ft_putnbr_fd(nb, 1);
}

void	ft_putunbr(unsigned long long nb)
{
	ft_putunbr_fd(nb, 1);
}

void	ft_putlnbr(long long nb)
{
	ft_putlnbr_fd(nb, 1);
}

void	ft_putumaxnbr(uintmax_t nb)
{
	ft_putumaxnbr_fd(nb, 1);
}
void	ft_putimaxnbr(intmax_t nb)
{
	ft_putimaxnbr_fd(nb, 1);
}