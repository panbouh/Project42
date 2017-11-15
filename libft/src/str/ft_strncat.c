/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:20:08 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/24 18:26:05 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(dest);
	while (src[i] && i < n)
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = 0;
	return (dest);
}
