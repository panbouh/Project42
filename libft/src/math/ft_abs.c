/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:09:59 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:10:02 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

unsigned long long	ft_abs_ll(long long n)
{
	unsigned long long	res;

	if (n < 0)
	{
		res = -n;
		return (res);
	}
	return ((unsigned long long)n);
}

unsigned long		ft_abs_l(long n)
{
	unsigned long	res;

	if (n < 0)
	{
		res = -n;
		return (res);
	}
	return ((unsigned long)n);
}

unsigned int		ft_abs(int n)
{
	unsigned int	res;

	if (n < 0)
	{
		res = -n;
		return (res);
	}
	return ((unsigned int)n);
}

uintmax_t			ft_abs_imax(intmax_t n)
{
	uintmax_t	res;

	if (n < 0)
	{
		res = -n;
		return (res);
	}
	return ((uintmax_t)n);
}
