/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:35:31 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/25 15:43:16 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	size;

	if (!(*str) && !(*to_find))
		return ((char *)str);
	i = 0;
	size = ft_strlen(to_find);
	while (str[i] && i < n)
	{
		if (size > (n - i))
			return (NULL);
		if (ft_strncmp(&str[i], to_find, size) == OK)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
