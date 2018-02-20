/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 18:54:29 by ccatoire          #+#    #+#             */
/*   Updated: 2017/04/25 18:54:31 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	new = ft_memset(new, '\0', size + 1);
	return (new);
}
