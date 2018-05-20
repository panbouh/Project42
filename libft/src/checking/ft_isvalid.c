/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:00:08 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:00:10 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isvalid(char c, char *valid)
{
	size_t	i;

	i = 0;
	while (valid[i])
	{
		if (c == valid[i])
			return (OK);
		i++;
	}
	return (FAIL);
}
