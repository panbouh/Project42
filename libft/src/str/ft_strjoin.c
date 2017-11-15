/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:30:42 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/27 16:30:43 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*juin;
	size_t			size_all;
	size_t			i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	size_all = ft_strlen(s1) + ft_strlen(s2);
	if (!(juin = malloc(sizeof(char) * size_all + 1)))
		return (NULL);
	while (s1[i])
	{
		juin[i] = s1[i];
		i++;
	}
	juin[i] = 0;
	juin = ft_strcat(juin, s2);
	return (juin);
}
