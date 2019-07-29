/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:29:12 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:29:12 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_to(const char *s, unsigned int start, char stop)
{
	char			tronc[BUFF_MAX];
	unsigned int	i;

	if (!s)
		return (NULL);
	ft_bzero(tronc, BUFF_MAX);
	i = 0;
	while (s[i] && s[i] != stop)
	{
		tronc[i] = s[start];
		start++;
		i++;
	}
	tronc[i] = 0;
	return (ft_strdup(tronc));
}
