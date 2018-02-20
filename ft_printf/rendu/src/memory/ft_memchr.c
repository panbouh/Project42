/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:44:20 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/24 17:00:15 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*ptr;
	unsigned char		uc;
	size_t				i;

	ptr = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (ptr[i] == uc)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
