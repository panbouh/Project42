/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 12:19:56 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/16 12:19:57 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		test_neg(long *nb, char *s, size_t *i, size_t *div)
{
	if (*nb < 0)
	{
		s[(*i)++] = '-';
		*nb *= -1;
		*div /= 10;
	}
}

char			*ft_itoa(int n)
{
	size_t	i;
	size_t	size;
	size_t	div;
	char	*str;
	long	nb;

	i = 0;
	nb = n;
	if ((size = ft_count_digit(nb)) == 0)
		size = 1;
	if ((div = ft_power(10, size - 1)) == 0)
		div = 1;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	test_neg(&nb, str, &i, &div);
	while (i < size)
	{
		str[i++] = (nb / div) + 48;
		nb = nb % div;
		div /= 10;
	}
	str[i] = 0;
	return (str);
}
