/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:27:49 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:27:50 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_newpath(const char *path, const char *name)
{
	char	new[BUFF_MAX];
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	ft_bzero(new, BUFF_MAX);
	if (name[0] && name[0] != '/')
		ft_strcat(new, path);
	i = ft_strlen(new);
	if (new[ft_abs(i - 1)] && new[ft_abs(i - 1)] != '/')
		new[i++] = '/';
	ft_strcat(new, name);
	return (ft_strdup(new));
}
