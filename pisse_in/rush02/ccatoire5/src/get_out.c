/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:53:38 by ccatoire          #+#    #+#             */
/*   Updated: 2017/03/26 23:12:08 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "colle02.h"

char		*ft_realloc(char *str, int new_size)
{
	char	*new;
	int		i;
	int		size;

	size = ft_strlen(str, '\0') + new_size;
	if (!(new = malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (!str)
		return (new);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	return (new);
}

char		*get_out(void)
{
	int		rd;
	int		i;
	char	buffer;
	char	*out;

	i = 0;
	out = NULL;
	while ((rd = read(0, &buffer, 1)) && rd != -1)
	{
		if (!(out = ft_realloc(out, sizeof(char))))
			return (NULL);
		out[i] = buffer;
		out[i + 1] = '\0';
		i++;
	}
	return (out);
}
