/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_full.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:30:49 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:30:52 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_full(const char *str)
{
	char	trim[424242];
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	ft_bzero(trim, 424242);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			trim[y++] = str[i];
		i++;
	}
	return (ft_strdup(trim));
}
