/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:43:43 by ccatoire          #+#    #+#             */
/*   Updated: 2017/05/30 17:43:45 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrev(char *s)
{
	size_t			size;
	unsigned int	i;
	char			save;

	i = 0;
	size = ft_strlen(s);
	while (i < size / 2)
	{
		save = s[i];
		s[i] = s[size - 1 - i];
		s[size - 1 - i] = save;
		i++;
	}
	return (s);
}
