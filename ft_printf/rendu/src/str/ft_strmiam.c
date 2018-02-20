/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmiam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:19:34 by ccatoire          #+#    #+#             */
/*   Updated: 2017/11/20 19:19:35 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmiam(char *str, char stop)
{
	size_t	i;
	char	*burp;

	i = 0;
	if (!str)
		return (NULL);
	i = ft_skip_char(str, i, stop, TILL);
	if (!str[i] || !str[i + 1])
	{
		ft_strdel(&str);
		return (NULL);
	}
	else
	{
		if (!(burp = ft_strdup(&str[i + 1])))
			return (NULL);
	}
	burp[ft_strlen(burp) + 1] = 0;
	ft_strdel(&str);
	return (burp);
}
