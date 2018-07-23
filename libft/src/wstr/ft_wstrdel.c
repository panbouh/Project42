/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccatoire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:35:14 by ccatoire          #+#    #+#             */
/*   Updated: 2018/05/20 18:35:16 by ccatoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wuni.h"
#include "libft.h"

int	ft_wstrdel(wchar_t **was)
{
	if (was && *was)
	{
		free(*was);
		*was = NULL;
		return (OK);
	}
	return (FAIL);
}
