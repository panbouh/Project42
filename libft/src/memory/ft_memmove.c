/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 15:39:23 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/24 16:39:15 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;
	char		save;

	d = dest;
	s = src;
	i = 0;
	save = s[i];
	if (d <= s)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
	return (dest);
}
