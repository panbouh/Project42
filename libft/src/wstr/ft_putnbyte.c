/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbyte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:34:56 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:34:57 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wuni.h"

int	ft_putnbyte(const wchar_t *wstr, size_t n)
{
	size_t	i;
	size_t	size;
	int		ret;
	int		stop;

	i = 0;
	ret = 0;
	stop = 0;
	if ((size = ft_wstrlen(wstr)) < n)
		n = size;
	while (wstr[i])
	{
		if ((stop += ft_wcharlen(wstr[i])) > (int)n)
			return (ret);
		ret += ft_putwchar(wstr[i]);
		i++;
	}
	return (ret);
}
