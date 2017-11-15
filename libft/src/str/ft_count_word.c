/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 13:30:37 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/30 13:30:41 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_word(const char *str, char space)
{
	size_t	i;
	size_t	count;
	size_t	size;

	i = 0;
	count = 0;
	size = ft_strlen(str);
	while (str[i])
	{
		i = ft_skip_char(str, i, space, TILL);
		if (i != size)
			count++;
		i = ft_skip_char(str, i, space, ALL);
	}
	return (count);
}
