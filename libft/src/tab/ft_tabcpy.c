/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:33:48 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:33:48 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"

char	**ft_tabcpy(char **dest, char **src)
{
	size_t	i;

	i = 0;
	while (dest[i])
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	return (dest);
}
