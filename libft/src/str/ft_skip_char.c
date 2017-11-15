/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:26:53 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/16 14:30:50 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_skip_char(const char *str, size_t i, char c, int flags)
{
	if (flags == ALL)
		while (str[i] && str[i] == c)
			i++;
	if (flags == TILL)
		while (str[i] && str[i] != c)
			i++;
	return (i);
}
