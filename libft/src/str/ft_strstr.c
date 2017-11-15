/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:09:11 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/25 15:33:16 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	size;

	if (!(*str) && !(*to_find))
		return ((char *)str);
	i = 0;
	size = ft_strlen(to_find);
	while (str[i])
	{
		if (ft_strncmp(&str[i], to_find, size) == OK)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
