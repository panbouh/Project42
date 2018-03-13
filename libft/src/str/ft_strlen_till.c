/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_till.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:28:30 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/30 13:28:33 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_till(const char *str, char stop)
{
	size_t	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size] && str[size] != stop)
		size++;
	return (size);
}

size_t	ft_strlen_till_skipspace(const char *str, char stop)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[size] && str[size] != stop)
		if (!ft_isspace(str[i]))
			size++;
	return (size);
}
