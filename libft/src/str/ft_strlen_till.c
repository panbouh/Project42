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
	while (str[size] && str[size] != stop)
		size++;
	return (size);
}
