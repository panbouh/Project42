/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:26:20 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/25 14:39:57 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dstlen;

	d = dest;
	s = src;
	n = size;
	while (n-- != 0 && *d)
		d++;
	dstlen = d - dest;
	n = size - dstlen;
	if (n == 0)
		return (dstlen + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = 0;
	return (dstlen + (s - src));
}

/*
**size_t		ft_strlcat(char *dst, const char *src, size_t size)
**{
**	size_t	i;
**	size_t	y;
**	size_t	n;
**	n = size;
**	i = 0;
**	y = 0;
**	while (n-- != 0 && dst[i] != '\0')
**		i++;
**	if (i == size)
**		return (i + ft_strlen(src));
**	while (src[y] != '\0')
**	{
**		if (i < size - 1)
**			dst[i] = src[y];
**		i++;
**		y++;
**	}
**	dst[i] = '\0';
**	return (i);
**}
*/
