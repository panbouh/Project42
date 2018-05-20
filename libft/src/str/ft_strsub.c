/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:48:17 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/27 14:48:18 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*tronc;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(tronc = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		tronc[i] = s[start];
		start++;
		i++;
	}
	tronc[i] = 0;
	return (tronc);
}
