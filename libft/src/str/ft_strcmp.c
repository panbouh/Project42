/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:43:55 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/25 15:58:39 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (FAIL);
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
** int				ft_strcmp(const char *s1, const char *s2)
** {
** 	size_t		i;
** 	i = 0;
** 	while (s1[i] && s2[i] && s1[i] == s2[i])
** 		i++;
** 	return ((unsigned int)(s1[i]) - (unsigned int)(s2[i]));
** }
*/
