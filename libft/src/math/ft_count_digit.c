-/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:48:30 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/30 17:48:32 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_lldigit(long long n)
{
	size_t				count;
	unsigned long long	nb;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	nb = ft_abs_ll(n);
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

size_t	ft_count_ldigit(long n)
{
	size_t			count;
	unsigned long	nb;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	nb = ft_abs_l(n);
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

size_t	ft_count_digit(int n)
{
	size_t			count;
	unsigned int	nb;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	nb = ft_abs(n);
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

size_t	ft_count_udigit(unsigned long n)
{
	size_t			count;

	count = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}
