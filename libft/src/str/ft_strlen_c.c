/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:28:09 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:28:09 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t		ft_strlen_c(const char *str, char c)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
		if (str[i++] == c)
			size++;
	return (size);
}
