/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:00:39 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/27 17:00:41 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(const char *s)
{
	unsigned int	start;
	unsigned int	end;
	size_t			size;

	if (!s)
		return (NULL);
	if (*s == 0)
		return (ft_strdup(s));
	start = 0;
	size = ft_strlen(s);
	end = size - 1;
	while (s[start]
		&& (s[start] == ' ' || s[start] == '\t' || s[start] == '\n'))
		start++;
	while (end > start && s[end]
		&& (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	if (start == 0 && end == size - 1)
		return (ft_strdup(s));
	return (ft_strsub(s, start, (end - start + 1)));
}
