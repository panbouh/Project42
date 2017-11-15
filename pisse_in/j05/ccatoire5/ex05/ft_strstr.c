/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:42:58 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/29 12:42:14 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		same_thing(char *thing, char *to_find)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (to_find[size])
		size++;
	while (thing[i] && to_find[i])
	{
		if (thing[i] != to_find[i])
			return (0);
		i++;
	}
	if (!thing[i] && i != size)
		return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find == 0 || str == 0)
		return (str);
	while (str[i])
	{
		if (same_thing(&str[i], to_find) == 1)
			return (&str[i]);
		i++;
	}
	return (0);
}
